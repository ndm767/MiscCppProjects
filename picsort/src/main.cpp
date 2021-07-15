#include "Picsort.hpp"

#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "no file specified!" << std::endl;
        return 0;
    }

    std::string imgPath(argv[1]);

    Picsort ps(imgPath);
    ps.run();

    return 0;
}