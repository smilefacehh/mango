cmake_minimum_required(VERSION 3.0.2)
project(orange)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g")


find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

catkin_package(

)

include_directories(
  ${catkin_INCLUDE_DIRS}
  src/ # 这样写之后，头文件包含就不用从src开始了
)

file(GLOB SRC
  src/common/*.cpp        src/common/*.h        src/common/*.hpp
  src/localization/*.cpp  src/localization/*.h  src/localization/*.hpp
  src/mapping/*.cpp       src/mapping/*.h       src/mapping/*.hpp
  src/perception/*.cpp    src/perception/*.h    src/perception/*.hpp
  src/planning/*.cpp      src/planning/*.h      src/planning/*.hpp
)

add_library(slam ${SRC})
# target_link_libraries(libOrange)

add_executable(orange src/System.cpp)
target_link_libraries(orange ${catkin_LIBRARIES} slam)