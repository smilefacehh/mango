#include <iostream>
#include <queue>
#include <chrono>

#include <ros/ros.h>
#include <ros/time.h>
#include <ros/publisher.h>
#include <ros/subscriber.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>

#include "base/Pose.hpp"
#include "base/LaserScan.hpp"
#include "base/Imu.hpp"
#include "base/Odometry.hpp"
#include "Localization.h"
#include "Mapping.h"
#include "Optimize.h"

class System
{
public:
    System(ros::NodeHandle& nh);
    ~System() {}

    void Loop();
private:
    // 从缓存队列取一帧数据，帧率、与当前时间接近、与上一次处理帧的间隔
    LaserScanConstPtr GetALaserScan();
    // 取上一帧激光到当前帧激光之间的IMU数据
    std::queue<ImuConstPtr> GetImuQ(float startTime, float endTime);

    // 接收数据
    void SubLaserScanCallback(const sensor_msgs::LaserScanConstPtr& laserScanMsg);
    void SubImuCallback(const sensor_msgs::ImuConstPtr& imuMsg);
    void SubOdometryCallback(const nav_msgs::OdometryConstPtr& odometryMsg);

    ros::Subscriber mSubLaserScan;
    ros::Subscriber mSubImu;
    ros::Subscriber mSubOdometry;

    // 数据队列
    std::queue<LaserScanConstPtr> mqLaserScan;
    std::queue<ImuConstPtr> mqImu;
    std::queue<OdometryConstPtr> mqOdometry;

    float mLastProcessTime; // 上一次处理的帧时间
    float mCurrentTime;     // 当前系统时间
    float pmMaxTimeDiff;    // 参数，当前时间之前太久的帧不处理

    // 定位、建图、后端优化
    std::shared_ptr<Localization> mpLocalization;
    std::shared_ptr<Mapping> mpMapping;
    std::shared_ptr<Optimize> mpOptimize;
};

System::System(ros::NodeHandle& nh)
{
    mSubLaserScan = nh.subscribe<sensor_msgs::LaserScan>("/laser_scan", 30, &System::SubLaserScanCallback, this);
    mSubImu = nh.subscribe<sensor_msgs::Imu>("/imu", 200, &System::SubImuCallback, this);
    mSubOdometry = nh.subscribe<nav_msgs::Odometry>("/odometry", 200, &System::SubOdometryCallback, this);
}

void System::Loop()
{
    while (1)
    {
        mCurrentTime = ros::Time::now().nsec;
        LaserScanConstPtr laserScan = GetALaserScan();
        if(laserScan == nullptr)
        {
            continue;
        }
        std::queue<ImuConstPtr> imuQ = GetImuQ(mLastProcessTime, laserScan->timestamp);
        mLastProcessTime = laserScan->timestamp;

        // 定位
        mpLocalization->Process(laserScan, imuQ);
        Pose pose = mpLocalization->GetPose();

        // 优化
        mpOptimize->Process();

        // 建图
        mpMapping->ProcessLaserScan(laserScan, pose);
    }
}

LaserScanConstPtr System::GetALaserScan()
{
    LaserScanConstPtr laserScan;
    while(!mqLaserScan.empty())
    {
        if(mqLaserScan.front()->timestamp + pmMaxTimeDiff < mCurrentTime)
        {
            mqLaserScan.pop();
        }
        else
        {
            laserScan = mqLaserScan.front();
            mqLaserScan.pop();
            break;
        }
    }
    return laserScan;
}

std::queue<ImuConstPtr> System::GetImuQ(float startTime, float endTime)
{
    std::queue<ImuConstPtr> imuQ;
    while(!mqImu.empty())
    {
        if(mqImu.front()->timestamp < startTime)
        {
            mqImu.pop();
        }
        else if(mqImu.front()->timestamp > endTime)
        {
            break;
        }
        else
        {
            imuQ.push(mqImu.front());
            mqImu.pop();
        }
    }
    return imuQ;
}

void System::SubLaserScanCallback(const sensor_msgs::LaserScanConstPtr& laserScanMsg)
{
    LaserScanConstPtr laserScan(new LaserScan(laserScanMsg));
    mqLaserScan.push(laserScan);
}

void System::SubImuCallback(const sensor_msgs::ImuConstPtr& imuMsg)
{
    ImuConstPtr imu(new Imu(imuMsg));
    mqImu.push(imu);
}

void System::SubOdometryCallback(const nav_msgs::OdometryConstPtr& odometryMsg)
{
    OdometryConstPtr odometry(new Odometry(odometryMsg));
    mqOdometry.push(odometry);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "orange");
    ros::NodeHandle nh;
    System sys(nh);
    sys.Loop();
    ros::spin();
    return 0;
}