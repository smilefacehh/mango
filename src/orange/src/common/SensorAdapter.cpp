#include "SensorAdapter.h"

namespace mango
{
/**
 * ros格式的LaserScan消息转换成mango::LaserScan结构
 * 
 * @param laserScanMsg ros格式的LaserScan消息
*/
mango::LaserScan RosLaserScanToLaserScan(const sensor_msgs::LaserScanConstPtr& laserScanMsg)
{
    mango::LaserScan laserScan;
    laserScan.timestamp = laserScanMsg->header.stamp.toSec();
    laserScan.angleMin = laserScanMsg->angle_min;
    laserScan.angleMax = laserScanMsg->angle_max;
    laserScan.angleIncrement = laserScanMsg->angle_increment;
    laserScan.scanTime = laserScanMsg->scan_time;
    laserScan.rangeMin = laserScanMsg->range_min;
    laserScan.rangeMax = laserScanMsg->range_max;
    laserScan.ranges = laserScanMsg->ranges;
    laserScan.intensityes = laserScanMsg->intensities;
}

}