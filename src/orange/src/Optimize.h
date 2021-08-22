/**
 * 后端优化
 * 
 * 1.维护关键帧滑窗
 * 2.关键帧激光scan位姿、IMU与积分、里程计、闭环，一并优化
*/

#pragma once

class Optimize
{
public:
    Optimize();
    ~Optimize();

    void Process();
};