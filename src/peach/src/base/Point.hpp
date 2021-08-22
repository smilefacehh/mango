#pragma once
#include <iostream>
#include <Eigen/Core>

template <typename T>
class Point
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    Point() {}
    Point(T x, T y, T z, int r, int g, int b): x(x), y(y), z(z), r(r), g(g), b(b) {}
    Point(const Eigen::Matrix<T, 3, 1>& pt) 
    {
        x = pt(0);
        y = pt(1);
        z = pt(2);
    }
    Point(const Point& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
    }
    Point& operator=(const Point& rhs)
    {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
        return *this;
    }

    ~Point() {}
    
    bool operator==(const Point& pt)
    {
        return x == pt.x && y == pt.y && z == pt.z;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& pt)
    {
        os << "(" << pt.x << "," << pt.y << "," << pt.z << ")" << std::endl;
        return os;
    }

    Eigen::Matrix<T, 3, 1> EigenType()
    {
        return Eigen::Matrix<T, 3, 1>(x, y, z);
    }

    T x, y, z;
    int r, g, b;
};

typedef Point<float> Pointf;
typedef Point<double> Pointd;