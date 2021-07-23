#ifndef CONFIG_MGR_H_
#define CONFIG_MGR_H_

#include <string>

#include <Eigen/Eigen>

#include <opencv2/opencv.hpp>
// 当引用此头文件时，Eigen必须在此之前引用
#include <opencv2/core/eigen.hpp>

namespace mango {

class ConfigMgr
{
public:
    static ConfigMgr& getInstance()
    {
        static ConfigMgr config_mgr;
        return config_mgr;
    }

    void loadConfig(const std::string& path);

    std::string output_path;
    double image_width, image_height;
    double fx, fy, cx, cy;
    double k1, k2, p1, p2;
    Eigen::Matrix3d R_ic0;
    Eigen::Vector3d t_ic0;

private:
    ConfigMgr() {}
    ConfigMgr(const ConfigMgr& rhs) {}
    ConfigMgr& operator=(const ConfigMgr& rhs) {}
};

}

#endif