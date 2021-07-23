#ifndef SNESOR_ADAPTER_H_
#define SNESOR_ADAPTER_H_

#include "LaserScan.h"

#include "sensor_msgs/LaserScan.h"

namespace mango
{

// ros格式的LaserScan消息转换成mango::LaserScan结构
mango::LaserScanPtr RosLaserScanToLaserScan(const sensor_msgs::LaserScanConstPtr& laserScanMsg);

// mango::LaserScan数据转换成ros格式的LaserScan
sensor_msgs::LaserScanPtr LaserScanToRosLaserScan(const mango::LaserScanConstPtr& laserScanMsg);
}

#endif