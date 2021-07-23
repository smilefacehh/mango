#ifndef LASER_SCAN_H_
#define LASER_SCAN_H_

#include <memory>
#include <vector>

namespace mango
{

struct LaserScan
{
    double timestamp;
    float angleMin;
    float angleMax;
    float angleIncrement;
    float scanTime;
    float rangeMin;
    float rangeMax;
    std::vector<float> ranges;
    std::vector<float> intensityes;
};

typedef std::shared_ptr<LaserScan> LaserScanPtr;
typedef std::shared_ptr<LaserScan const> LaserScanConstPtr;
}
#endif