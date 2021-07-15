#include "ImgConverter.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

ImgConverter::ImgConverter(std::string path) {
    data = stbi_load(path.c_str(), &w, &h, &nc, 0);
}

ImgConverter::~ImgConverter() { stbi_image_free(data); }

void ImgConverter::convert() {
    for (int p = 0; p < w * h * nc; p += nc) {
        float total = 0.0f;
        for (int i = 0; i < nc; i++) {
            total += float(data[(p + i)]) / 255.0f;
        }
        total /= nc;
        std::cout << values.at(int(total * 69.0f));

        if (p % (w * nc) == 0) {
            std::cout << "\n";
        }
    }

    std::cout << std::flush;
}