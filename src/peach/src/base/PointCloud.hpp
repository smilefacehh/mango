#pragma once
#include <vector>
#include <Eigen/Core>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include "Point.hpp"

template <typename PointT>
class PointCloud
{
public:
    PointCloud() {}
    PointCloud(const PointCloud& rhs): points(rhs.points) {}
    PointCloud& operator=(const PointCloud& rhs)
    {
        points = rhs.points;
        return *this;
    }
    ~PointCloud() {}

    void push_back(const PointT& pt)
    {
        points.push_back(pt);
    }

    pcl::PointCloud<pcl::PointXYZRGB> PclTypeXYZRGB()
    {
        pcl::PointCloud<pcl::PointXYZRGB> cloud;
        for(int i = 0; i < points.size(); i++)
        {
            pcl::PointXYZRGB pt;
            pt.x = points[i].x;
            pt.y = points[i].y;
            pt.z = points[i].z;
            pt.r = points[i].r;
            pt.g = points[i].g;
            pt.b = points[i].b;
            cloud.points.push_back(pt);
        }
        cloud.width = cloud.points.size();
        cloud.height = 1;
        return cloud;
    }

    pcl::PointCloud<pcl::PointXYZ> PclTypeXYZ()
    {
        pcl::PointCloud<pcl::PointXYZ> cloud;
        for(int i = 0; i < points.size(); i++)
        {
            pcl::PointXYZ pt;
            pt.x = points[i].x;
            pt.y = points[i].y;
            pt.z = points[i].z;
            cloud.points.push_back(pt);
        }
        cloud.width = cloud.points.size();
        cloud.height = 1;
        return cloud;
    }

    std::vector<PointT> points;
};

typedef PointCloud<Pointf> PointCloudf;