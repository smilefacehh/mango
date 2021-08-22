#pragma once
#include <opencv2/opencv.hpp>
#include "base/Pose.hpp"
#include "base/PointCloud.hpp"


class Mapping
{
public:
    Mapping();
    ~Mapping();

    void Process(const cv::Mat& rgb, const cv::Mat& depth, const Pose& pose);

private:
    PointCloudf Depth2PointCloud(const cv::Mat& depth, const cv::Mat& rgb);
};