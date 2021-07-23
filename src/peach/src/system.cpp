#include "system.h"

namespace mango {

System::System() {}
System::~System() {}

void System::inputImage(double t, const cv::Mat& _img) {}
void System::inputIMU(double t, const Eigen::Vector3d& _linear_acc, const Eigen::Vector3d& _angular_vel) {}

}