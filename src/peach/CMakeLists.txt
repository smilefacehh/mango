cmake_minimum_required(VERSION 2.8.13)
project(peach)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Eigen3_INCLUDE_DIRS})

file(GLOB SRC src/*.cpp include/*.h)
# 类似环境变量的作用，添加此行，代码中直接#include对应头文件名即可
include_directories(include/)

add_library(peach_lib ${SRC})
target_link_libraries(peach_lib ${OpenCV_LIBS})

add_executable(peach mono.cpp)
target_link_libraries(peach peach_lib)