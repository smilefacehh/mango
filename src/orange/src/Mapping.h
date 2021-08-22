/**
 * 建图
 * 
 * 1.局部地图
 * 2.全局地图
*/

#pragma once
#include "base/LaserScan.hpp"
#include "base/Pose.hpp"

class Mapping
{
public:
    Mapping();
    ~Mapping();

    void ProcessLaserScan(const LaserScanConstPtr& laserScan, const Pose& pose);
};