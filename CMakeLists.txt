cmake_minimum_required(VERSION 3.15)
project(MyFastSlam)

set(CMAKE_CXX_STANDARD 14)

include_directories(src include src/Eigen)

add_executable(MyFastSlam src/main.cpp src/kalman.cpp)

