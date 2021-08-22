#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>

#include "base/Pose.hpp"
#include "base/Imu.hpp"
#include "Tracking.h"
#include "Mapping.h"
#include "Optimize.h"
#include "Util.h"
#include "Config.hpp"

class System
{
public:
    System(const std::string& configFile);
    ~System();

    void Loop();

private:
    // 加载一帧图像、深度图、imu数据
    void LoadData(int id, cv::Mat& rgb, cv::Mat& depth, std::queue<ImuConstPtr>& imuQ, double& timestamp);

    int num_frames;

    std::shared_ptr<Tracking> mpTracking;
    std::shared_ptr<Mapping> mpMapping;
    std::shared_ptr<Optimize> mpOptimize;
};

System::System(const std::string& configFile)
{
    Config::GetInstance().LoadConfig(configFile);
    num_frames = Config::GetInstance().vRgbFiles.size();

    mpTracking = std::shared_ptr<Tracking>(new Tracking());
    mpMapping = std::shared_ptr<Mapping>(new Mapping());
    mpOptimize = std::shared_ptr<Optimize>(new Optimize());
}

System::~System() {}

void System::Loop()
{
    int id = 0;
    while(1)
    {
        auto t = std::chrono::steady_clock::now();
        double timestamp;
        cv::Mat rgb, depth;
        std::queue<ImuConstPtr> imuQ;
        LoadData(id, rgb, depth, imuQ, timestamp);

        mpTracking->Process(rgb, depth, imuQ);
        Pose pose = mpTracking->GetPose();

        mpOptimize->Process();

        mpMapping->Process(rgb, depth, pose);

        id++;
        auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t).count();
        float fps = 1000 / dt;
        std::cout << "frame:" << id << ", cost:" << dt << "ms, fps:" << fps << std::endl;
        if(id > num_frames)
        {
            break;
        }
    }
}

void System::LoadData(int id, cv::Mat& rgb, cv::Mat& depth, std::queue<ImuConstPtr>& imuQ, double& timestamp)
{
    if(id < num_frames)
    {
        rgb = cv::imread(Config::GetInstance().vRgbFiles[id], cv::IMREAD_UNCHANGED);
        depth = cv::imread(Config::GetInstance().vDepthFiles[id], cv::IMREAD_UNCHANGED);
        timestamp = Config::GetInstance().vTimestamps[id];
    }
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "Usage:./slam ../config/tum_rgbd.yaml" << std::endl;
        return -1;
    }
    System sys(argv[1]);
    sys.Loop();
    return 0;
}