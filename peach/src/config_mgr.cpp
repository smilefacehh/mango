#include "config_mgr.h"

namespace mango {

void ConfigMgr::loadConfig(const std::string& path)
{
    FILE* fh = fopen(path.c_str(), "r");
    if(fh == NULL)
    {
        std::cerr << "Error: config file dosen't exist" << std::endl;
        return;
    }
    fclose(fh);

    cv::FileStorage fs(path, cv::FileStorage::READ);
    if(!fs.isOpened())
    {
        std::cerr << "Error: check config file's format" << std::endl;
    }

    fs["output_path"] >> output_path;
    fs["image_width"] >> image_width;
    fs["image_height"] >> image_height;
    fs["intrinsics"]["fx"] >> fx;
    fs["intrinsics"]["fy"] >> fy;
    fs["intrinsics"]["cx"] >> cx;
    fs["intrinsics"]["cy"] >> cy;
    fs["distortion_parameters"]["k1"] >> k1;
    fs["distortion_parameters"]["k2"] >> k2;
    fs["distortion_parameters"]["p1"] >> p1;
    fs["distortion_parameters"]["p2"] >> p2;
    
    cv::Mat cv_T;
    Eigen::Matrix4d eigen_T;
    fs["T_body_cam0"] >> cv_T;
    cv::cv2eigen(cv_T, eigen_T);
    R_ic0 = eigen_T.block<3, 3>(0, 0);
    t_ic0 = eigen_T.block<3, 1>(0, 3);
}

}