#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

#include "Util.h"

class Config
{
public:
    static Config& GetInstance()
    {
        static Config config;
        return config;
    }

    std::string dataset;
    std::vector<double> vTimestamps;
    std::vector<std::string> vRgbFiles;
    std::vector<std::string> vDepthFiles;

    float fx, fy, cx, cy;
    float ds;

    void LoadConfig(const std::string& configFile)
    {
        cv::FileStorage fs(configFile, cv::FileStorage::READ);
        if(!fs.isOpened())
        {
            std::cerr << "cannot open config file:" << configFile << std::endl;
            return;
        }

        fs["dataset"] >> dataset;

        // 读取图像序列
        std::ifstream associateIfs(JoinPath(dataset, "associate.txt"));
        if(associateIfs.is_open())
        {
            std::string line;
            while(!associateIfs.eof())
            {
                double ts;
                std::string sRGB, sD;
                getline(associateIfs, line);
                std::istringstream iss(line);
                iss >> ts;
                vTimestamps.push_back(ts);
                iss >> sRGB;
                vRgbFiles.push_back(JoinPath(dataset, sRGB));
                iss >> ts >> sD;
                vDepthFiles.push_back(JoinPath(dataset, sD));
            }
        }
        associateIfs.close();

        // 相机内参
        fs["intrinsics"]["fx"] >> fx;
        fs["intrinsics"]["fy"] >> fy;
        fs["intrinsics"]["cx"] >> cx;
        fs["intrinsics"]["cy"] >> cy;

        // 深度图像尺度
        fs["depth"]["ds"] >> ds;

        fs.release();
    }
};
