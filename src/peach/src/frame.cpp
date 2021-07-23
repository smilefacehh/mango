#include "frame.h"

namespace mango
{
Frame::Frame() {}
    
Frame::Frame(const Frame& rhs) {}

Frame& Frame::operator=(const Frame& rhs) 
{
    return *this;
}

Frame::Frame(const cv::Mat& im_gray, const double& timestamp, Feature::Ptr feature)
{

}
}