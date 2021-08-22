#pragma once
#include <queue>
#include <vector>

#include "opencv2/opencv.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/features2d.hpp"
#include "base/Imu.hpp"
#include "base/Pose.hpp"


class Tracking
{
public:
    Tracking();
    ~Tracking();

    void Process(const cv::Mat& rgb, const cv::Mat& depth, const std::queue<ImuConstPtr>& imuQ);
    Pose GetPose();

private:
    // 上一帧特征点、描述子
    cv::Mat mLastRGB;
    std::vector<cv::KeyPoint> mLastFrameKpts;
    cv::Mat mLastFrameDescriptors;

    // 特征提取
    cv::Ptr<cv::ORB> mOrbExtractor;
    cv::Ptr<cv::xfeatures2d::BriefDescriptorExtractor> mDescriptorExtractor;

    bool mbInitialized;

    Pose mPose;
};