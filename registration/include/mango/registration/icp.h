/**
 * Iterative Closest Point
 * 迭代最近点算法
 */

#pragma once

#include <memory>


namespace mango {

/**
 * 算法终止条件
 * 1.达到设置的最大迭代次数；
 * 2.两次迭代之间变换差值小于一定阈值；
 * 3.SSE（Sum of Euclidean squared errors）小于一定阈值。
*/
template <typename PointSource, typename PointTarget, typename Scalar = float>
class IterativeClosestPoint
{
public:
    using Ptr = std::shared_ptr<IterativeClosestPoint<PointSource, PointTarget, Scalar>>;
    using ConstPtr = std::shared_ptr<const IterativeClosestPoint<PointSource, PointTarget, Scalar>>;

    IterativeClosestPoint()
    {}

    ~IterativeClosestPoint() {}

private:
};

}