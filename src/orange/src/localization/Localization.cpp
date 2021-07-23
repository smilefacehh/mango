#include "Localization.h"

namespace mango
{
Localization::Localization() {}
Localization::~Localization() {}

bool Localization::IsBusy() 
{
    return false;
}
void Localization::ProcessLaserScan(const mango::LaserScanConstPtr& laserScan)
{

}
}