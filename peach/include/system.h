#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "config_mgr.h"
#include "initialize.h"

namespace mango {

class System
{
public:
    System();
    ~System();

    void inputImage(double t, const cv::Mat& _img);
    void inputIMU(double t, const Eigen::Vector3d& _linear_acc, const Eigen::Vector3d& _angular_vel);
private:
    Initialize initialize_;
};

}

#endif