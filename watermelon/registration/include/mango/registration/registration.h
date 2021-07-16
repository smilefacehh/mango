/**
 * Registration
 * 配准基类
 */

#pragma once

#include <memory>

#include <pcl/point_base.h>

namespace mango {

template <typename PointSource, typename PointTarget, typename Scalar = float>
class Registration
{
public:
    using Ptr = std::shared_ptr<Registration<PointSource, PointTarget, Scalar>>;
    using ConstPtr = std::shared_ptr<const Registration<PointSource, PointTarget, Scalar>>;

    using PointCloudSource = pcl::PointCloud<PointSource>;
    using PointCloudSourcePtr = typename PointCloudSource::Ptr;
    using PointCloudSourceConstPtr = typename PointCloudSource::ConstPtr;

    using PointCloudTarget = pcl::PointCloud<PointTarget>;
    using PointCloudTargetPtr = typename PointCloudTarget::Ptr;
    using PointCloudTargetConstPtr = typename PointCloudTarget::ConstPtr;

    Registration() {}
    ~Registration() {}

    virtual void setInputSource()(const PointCloudSourceConstPtr& cloud);

    inline PointCloudSourceConstPtr const getInputSource()
    {
        return input_;
    }
protected:
    /***/
    int max_iterations_;
};

}