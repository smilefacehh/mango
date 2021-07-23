#ifndef LOCALIZATION_H_
#define LOCALIZATION_H_

#include "common/LaserScan.h"

namespace mango
{

class Localization
{
public:
    Localization();
    ~Localization();

    bool IsBusy();
    void ProcessLaserScan(const mango::LaserScanConstPtr& laserScan);
};

}

#endif