cmake_minimum_required(VERSION 3.12)
set(PROJ_NAME "HdriToCubemap")
project(${PROJ_NAME} VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)


option(HDRITOCUBEMAP_USE_OPENCL "Use OpenCL for calculating the cubemap faces" ON)
option(HDRITOCUBEMAP_BUILD_DEMO_EXE "Build a demo executable target" ON)

add_subdirectory("HdriToCubemap")