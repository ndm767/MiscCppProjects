#pragma once

#include <string>

class ImgConverter {
  public:
    ImgConverter(std::string path);
    ~ImgConverter();

    void convert();

  protected:
    int w, h, nc;
    unsigned char *data;

    std::string values = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/"
                         "\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
};