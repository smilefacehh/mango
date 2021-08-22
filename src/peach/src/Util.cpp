#include "Util.h"

/**
 * 拼接路径
*/
std::string JoinPath(const std::string& path, const std::string& file)
{
    if(path.back() == '/')
    {
        return path + file;
    }
    return path + "/" + file;
}