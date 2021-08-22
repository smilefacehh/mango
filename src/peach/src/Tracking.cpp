#include "Tracking.h"


Tracking::Tracking()
    : mbInitialized(false)
{
    mOrbExtractor = cv::ORB::create(50);
    mDescriptorExtractor = cv::xfeatures2d::BriefDescriptorExtractor::create();
}
Tracking::~Tracking() {}

void Tracking::Process(const cv::Mat& rgb, const cv::Mat& depth, const std::queue<ImuConstPtr>& imuQ)
{
    cv::Mat gray;
    cv::cvtColor(rgb, gray, cv::COLOR_BGR2GRAY);

    std::vector<cv::KeyPoint> kpts;
    cv::Mat descriptors;
    mOrbExtractor->detect(gray, kpts);
    mDescriptorExtractor->compute(gray, kpts, descriptors);

    if(mbInitialized)
    {
        cv::BFMatcher matcher(cv::NORM_HAMMING2);
        std::vector<cv::DMatch> matches;
        matcher.match(mLastFrameDescriptors, descriptors, matches);
        cv::Mat matchRGB;
        cv::drawMatches(mLastRGB, mLastFrameKpts, rgb, kpts, matches, matchRGB);
        // cv::imshow("1", matchRGB);
        // cv::waitKey(-1);
        // cv::destroyAllWindows();
    }

    mLastFrameKpts = kpts;
    mLastFrameDescriptors = descriptors;
    mLastRGB = rgb;
    mbInitialized = true;
}

Pose Tracking::GetPose()
{
    return mPose;
}