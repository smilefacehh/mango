cmake_minimum_required(VERSION 2.8.13)
project(peach)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${Eigen3_INCLUDE_DIRS})
include_directories(${PCL_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

file(GLOB SRC src/*.cpp src/*.h src/*.hpp src/base/*.hpp)

add_executable(slam ${SRC})
target_link_libraries(slam ${OpenCV_LIBS} ${PCL_LIBRARIES})