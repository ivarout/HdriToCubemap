#include "HdriToCubemap.hpp"

int main()
{
    HdriToCubemap<unsigned char> hdri2cubemap("<path to panoramic image>", 512, true);
    hdri2cubemap.writeCubemap("<output folder>"); //optionally, specify an output folder
}