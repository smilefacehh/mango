#include "SensorAdapter.h"

namespace mango
{
/**
 * ros格式的LaserScan消息转换成mango::LaserScan结构
 * 
 * @param laserScanMsg ros格式的LaserScan消息
*/
mango::LaserScanPtr RosLaserScanToLaserScan(const sensor_msgs::LaserScanConstPtr& laserScanMsg)
{
    mango::LaserScanPtr laserScan(new mango::LaserScan);
    laserScan->timestamp = laserScanMsg->header.stamp.toSec();
    laserScan->angleMin = laserScanMsg->angle_min;
    laserScan->angleMax = laserScanMsg->angle_max;
    laserScan->angleIncrement = laserScanMsg->angle_increment;
    laserScan->scanTime = laserScanMsg->scan_time;
    laserScan->rangeMin = laserScanMsg->range_min;
    laserScan->rangeMax = laserScanMsg->range_max;
    laserScan->ranges = laserScanMsg->ranges;
    laserScan->intensityes = laserScanMsg->intensities;
    return laserScan;
}

/**
 * mango::LaserScan数据转换成ros格式的LaserScan
 * 
 * @param laserScanMsg mango格式的LaserScan数据
*/
sensor_msgs::LaserScanPtr LaserScanToRosLaserScan(const mango::LaserScanConstPtr& laserScanMsg)
{
    sensor_msgs::LaserScanPtr laserScan(new sensor_msgs::LaserScan);
    laserScan->header.stamp = ros::Time(laserScanMsg->timestamp);
    laserScan->angle_min = laserScanMsg->angleMin;
    laserScan->angle_max = laserScanMsg->angleMax;
    laserScan->angle_increment = laserScanMsg->angleIncrement;
    laserScan->scan_time = laserScanMsg->scanTime;
    laserScan->range_min = laserScanMsg->rangeMin;
    laserScan->range_max = laserScanMsg->rangeMax;
    laserScan->ranges = laserScanMsg->ranges;
    laserScan->intensities = laserScanMsg->intensityes;
    return laserScan;
}

}