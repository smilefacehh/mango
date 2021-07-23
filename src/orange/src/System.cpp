/**
 * 程序入口
*/
#include <iostream>
#include <deque>

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <ros/subscriber.h>
#include <ros/publisher.h>

#include "common/LaserScan.h"
#include "common/SensorAdapter.h"

namespace mango
{

class System
{
public:
    System(ros::NodeHandle& nh);
    ~System() {}

    void Loop();
private:
    void SubLaserScanCallback(const sensor_msgs::LaserScanConstPtr& laserScanMsg);

    ros::Subscriber mSubLaserScan;
    ros::Publisher mPubLaserScan;

    std::deque<mango::LaserScanPtr> mLaserScanData;
};

// 构造方法
System::System(ros::NodeHandle& nh)
{
    mSubLaserScan = nh.subscribe<sensor_msgs::LaserScan>("/raw_scan_with_pose", 30, &System::SubLaserScanCallback, this);
    mPubLaserScan = nh.advertise<sensor_msgs::LaserScan>("/mango_scan", 30);
}

void System::Loop()
{
    
}

// 激光雷达数据
void System::SubLaserScanCallback(const sensor_msgs::LaserScanConstPtr& laserScanMsg)
{
    mango::LaserScanPtr laserScan = mango::RosLaserScanToLaserScan(laserScanMsg);
    mLaserScanData.push_back(laserScan);
}
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "orange");
    ros::NodeHandle nh;
    mango::System sys(nh);
    sys.Loop();
    ros::spin();
    return 0;
}