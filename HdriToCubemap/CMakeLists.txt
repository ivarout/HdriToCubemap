add_library(HdriToCubemap INTERFACE)
target_include_directories(HdriToCubemap INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/ext)

if(HDRITOCUBEMAP_USE_OPENCL)
    if(WIN32)
        find_package(OpenCL 1.2 REQUIRED)
        if(OpenCL_FOUND)
            target_link_libraries (HdriToCubemap INTERFACE ${OpenCL_LIBRARY})
            target_include_directories(HdriToCubemap INTERFACE ${OpenCL_INCLUDE_DIRS})
            target_compile_definitions(HdriToCubemap INTERFACE USE_OPENCL
                                                                CL_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
                                                                CL_TARGET_OPENCL_VERSION=120)
        endif(OpenCL_FOUND)
    else()
        message(WARNING "OpenCL implementation is currently only supported on Windows, defaulted back to cpu implementation")
    endif(WIN32)
endif(HDRITOCUBEMAP_USE_OPENCL)

if(HDRITOCUBEMAP_BUILD_DEMO_EXE)
	add_executable(demo src/demo.cpp HdriToCubemap.hpp)
    target_link_libraries(demo PRIVATE HdriToCubemap)
endif(HDRITOCUBEMAP_BUILD_DEMO_EXE)