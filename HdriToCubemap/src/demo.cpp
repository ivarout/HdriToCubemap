#include "HdriToCubemap.hpp"

int main()
{
    HdriToCubemap<unsigned char> hdri2cubemap("/home/ivar/temp/shanghai_bund_1k.hdr", 512, true);
    hdri2cubemap.writeCubemap(""); //specify existing output folder
}