#pragma once
#include <memory>

class Imu
{
public:
    Imu() {}
    ~Imu() {}

    float timestamp;
};

typedef std::shared_ptr<Imu> ImuPtr;
typedef std::shared_ptr<const Imu> ImuConstPtr;