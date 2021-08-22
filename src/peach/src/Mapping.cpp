#include <pcl/io/pcd_io.h>

#include "Mapping.h"
#include "Config.hpp"
#include "base/Point.hpp"

Mapping::Mapping() {}
Mapping::~Mapping() {}

void Mapping::Process(const cv::Mat& rgb, const cv::Mat& depth, const Pose& pose) 
{
    PointCloudf cloud = Depth2PointCloud(depth, rgb);
    pcl::PointCloud<pcl::PointXYZRGB> cloudPCL = cloud.PclTypeXYZRGB();
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudPCLPtr(new pcl::PointCloud<pcl::PointXYZRGB>(cloudPCL));

    // pcl::io::savePCDFileASCII("pc.pcd", cloudPCL);
}

PointCloudf Mapping::Depth2PointCloud(const cv::Mat& depth, const cv::Mat& rgb)
{
    PointCloudf cloud;
    float X, Y, Z;
    int R, G, B;
    for(int r = 0; r < depth.rows; r++)
    {
        for(int c = 0; c < depth.cols; c++)
        {
            Z = depth.at<uint16_t>(r, c) / Config::GetInstance().ds;
            if(Z > 0)
            {
                X = (c - Config::GetInstance().cx) * Z / Config::GetInstance().fx;
                Y = (r - Config::GetInstance().cy) * Z / Config::GetInstance().fy;
                cv::Vec3b color = rgb.at<cv::Vec3b>(r, c);
                R = color(0);
                G = color(1);
                B = color(2);
                cloud.push_back(Pointf(X, Y, Z, R, G, B));
            }
        }
    }
    return cloud;
}