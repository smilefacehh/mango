#pragma once
#include <string>
#include <vector>
#include <sensor_msgs/LaserScan.h>

class LaserScan
{
public:
    LaserScan();
    LaserScan(const sensor_msgs::LaserScanConstPtr& laserScan);
    ~LaserScan();

    float timestamp;
    std::string frame_id;
    float angle_min;
    float angle_max;
    float angle_increment;
    float time_increment;
    float range_min;
    float range_max;
    std::vector<float> ranges;
    std::vector<float> intensities;
};

typedef std::shared_ptr<LaserScan> LaserScanPtr;
typedef std::shared_ptr<const LaserScan> LaserScanConstPtr;