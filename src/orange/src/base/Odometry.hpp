#pragma once
#include <memory>
#include <nav_msgs/Odometry.h>

class Odometry
{
public:
    Odometry();
    Odometry(const nav_msgs::OdometryConstPtr& odometry);
    ~Odometry();
};

typedef std::shared_ptr<Odometry> OdometryPtr;
typedef std::shared_ptr<const Odometry> OdometryConstPtr;