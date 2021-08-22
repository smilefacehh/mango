/**
 * 定位
 * 
 * 1.IMU预积分，计算位姿参提供初值，参与优化
 * 2.IMU校正激光点坐标
 * 3.里程计提供初值，参与优化（可选）
 * 4.scan-map匹配
 * 5.相邻帧scan-scan匹配，用前面一步的结果
*/

#pragma once
#include <queue>

#include "base/LaserScan.hpp"
#include "base/Imu.hpp"
#include "base/Pose.hpp"


class Localization
{
public:
    Localization();
    ~Localization();

    void Process(const LaserScanConstPtr& laserScan, const std::queue<ImuConstPtr>& imuQ);
    Pose GetPose();
};