#ifndef FEATURE_H_
#define FEATURE_H_

#include <memory>

namespace mango
{
class Feature
{
public:
    typedef std::shared_ptr<Feature> Ptr;

    Feature();
    virtual ~Feature() = 0;
};
}

#endif