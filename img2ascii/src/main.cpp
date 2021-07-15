#include "ImgConverter.hpp"

#include <memory>

int main(int argc, char *argv[]) {
    std::unique_ptr<ImgConverter> conv =
        std::make_unique<ImgConverter>(std::string(argv[1]));

    conv->convert();

    return 0;
}