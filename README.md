# Hdri To Cubemap 
This project contains a simple C++ library to convert hdri (equirectangular) environment maps to cubemaps, an example of which is shown below, for an hdri obtained from [HDRIHaven](https://hdrihaven.com/):

![GitHub Logo](hdri2cubemap.png)

To determine the 'color' of a pixel in one the cubemap's faces:
- The direction in 3D world space corresponding to the pixel is determined.
- The corresponding azimuth and elevation are calculated
- The environment map is sampled at the pixel corresponding to the calculated azimuth and elevation (for the equirectangular environment map the pixel distance along x and y are proportional to azimuth and elevation respectively)

Currently, [stb image](<https://github.com/nothings/stb>) is used for image loading and writing, providing support for many image formats. 

OpenCL support is provided for calculating the cubemap's faces (only tested on Windows). Do note that there is no big performance gain compared to the cpu implementation, since io operations take up most of the time.

# Installation
The only dependency of HdriToCubemap is [stb image](<https://github.com/nothings/stb>). Clone the repository using:
```
git clone https://github.com/ivarout/HdriToCubemap.git
cd HdriToCubemap
git submodule update --init --recursive
```
and in your project, link to the `HdriToCubemap` (interface) library.

Alternatively, simply copy the files `HdriToCubemap.hpp`, `stb_image.h`, and `stb_image_write.h` to an include location of your project.

When building through the CMake Gui, the `HDRITOCUBEMAP_USE_OPENCL` option can be checked if the user wishes to use the OpenCL implementation (currently only supported on Windows).

Note that C++17 is required (due to usage of std::clamp).

# Usage
Note that the template class `HdriToCubemap` supports `float` and `unsigned char` types, the first storing an hdr image, and the latter an 8-bit-per-channel ldr image. If the provided image is an hdr image, while the provided template type is `<unsigned char>`, [stb image](<https://github.com/nothings/stb>) will perform the conversion from hdr to ldr, and vice versa.

When constructing an instance of the `HdriToCubemap` class, the user has to provide a resolution to be used for the cubemap faces, and optionally a boolean which sets the filter type, which defaults to `true`, resulting in bilinear interpolation. When set to `false`, the *nearest* pixel in the environment map will be used.

```c++
// load hdr or ldr image
int cubemapResolution = 1024;
bool linearFilter = true; 

HdriToCubemap<float> hdriToCube_hdr("path_to_hdri_file", cubemapResolution, linearFilter);
HdriToCubemap<unsigned char> hdriToCube_ldr("path_to_hdri_file", cubemapResolution, linearFilter);

// use cubemap image directly
unsigned char* front = hdriToCube_ldr.getFront();
if (hdriToCube_ldr.getNumChannels() == 4)
{
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA8, hdriToCube.getCubemapResolution(), hdriToCube.getCubemapResolution(), 0, GL_RGBA, GL_UNSIGNED_BYTE, front);
}

// or output cube images to file (6 images will be output: "front.png", "back.png", "left.png", "right.png", "up.png", and "down.png")
hdriToCube_ldr.writeCubemap("output_directory");
```

## Other notes 

Any comments or suggestions related to code improvements and/or bugs are appreciated.
