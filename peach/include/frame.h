#ifndef FRAME_H_
#define FRAME_H_

#include <opencv2/opencv.hpp>

#include "feature.h"

namespace mango
{
class Frame
{
public:
    Frame();
    
    Frame(const Frame& rhs);

    Frame& operator=(const Frame& rhs);

    Frame(const cv::Mat& im_gray, const double& timestamp, Feature::Ptr feature);
};
}

#endif