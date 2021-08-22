#include "Localization.h"

Localization::Localization() {}
Localization::~Localization() {}

void Localization::Process(const LaserScanConstPtr& laserScan, const std::queue<ImuConstPtr>& imuQ) {}
Pose Localization::GetPose() 
{
    Pose pose;
    return pose;
}