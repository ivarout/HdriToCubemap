#include "HdriToCubemap.hpp"

int main()
{
    HdriToCubemap<unsigned char> hdri2cubemap("path_to_hdri_image", 512, true);
    hdri2cubemap.writeCubemap("output_folder");
}