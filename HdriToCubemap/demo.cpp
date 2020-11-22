#include "HdriToCubemap.hpp"

int main()
{
    HdriToCubemap<unsigned char> hdri2cubemap("C:/dev/HdriToCubemap_old/hdri/shanghai_bund_1k.hdr", 512, true);
    hdri2cubemap.writeCubemap("C:/dev/HdriToCubemap_old/output");
}