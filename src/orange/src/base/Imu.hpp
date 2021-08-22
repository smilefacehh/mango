#pragma once
#include <memory>
#include <sensor_msgs/Imu.h>

class Imu
{
public:
    Imu();
    Imu(const sensor_msgs::ImuConstPtr& imu);
    ~Imu();

    float timestamp;
};

typedef std::shared_ptr<Imu> ImuPtr;
typedef std::shared_ptr<const Imu> ImuConstPtr;