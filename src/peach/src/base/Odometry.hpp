#pragma once
#include <memory>

class Odometry
{
public:
    Odometry() {}
    ~Odometry() {}
};

typedef std::shared_ptr<Odometry> OdometryPtr;
typedef std::shared_ptr<const Odometry> OdometryConstPtr;