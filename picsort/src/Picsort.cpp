#include "Picsort.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <algorithm>
#include <iostream>
#include <vector>

Picsort::Picsort(std::string path) {
    running = true;
    data = stbi_load(path.c_str(), &w, &h, &nc, 0);

    if (nc < 3) {
        std::cout << "image doesn't have enough channels!" << std::endl;
        stbi_image_free(data);
        std::terminate();
    }

    SDL_Init(SDL_INIT_VIDEO);
    gWindow = SDL_CreateWindow("picsort", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
}

Picsort::~Picsort() {
    stbi_image_free(data);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

void Picsort::run() {
    while (running) {
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);

        for (int p = 0; p < (w * h * nc); p += nc) {
            int r = data[p];
            int g = data[p + 1];
            int b = data[p + 2];
            SDL_SetRenderDrawColor(gRenderer, r, g, b, 255);
            int x = (p / nc) % w;
            int y = ((p / nc) - ((p / nc) % w)) / w;
            SDL_RenderDrawPoint(gRenderer, x, y);
        }

        SDL_RenderPresent(gRenderer);

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    running = false;
                } else if (e.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                    sort();
                }
            }
        }
    }
}

void Picsort::sort() {
    struct pixel {
        int x, y;
        int r, g, b;
    };

    // sort by row (red)
    for (int y = 0; y < h; y++) {
        std::vector<pixel> row;
        for (int x = 0; x < w; x++) {
            pixel p;
            p.x = x;
            p.y = y;
            p.r = data[((y * w) + x) * nc];
            p.g = data[((y * w) + x) * nc + 1];
            p.b = data[((y * w) + x) * nc + 2];
            row.push_back(p);
        }

        std::sort(row.begin(), row.end(),
                  [](const pixel &a, const pixel &b) { return a.r < b.r; });

        for (int x = 0; x < w; x++) {
            data[((y * w) + x) * nc] = row.at(x).r;
            data[((y * w) + x) * nc + 1] = row.at(x).g;
            data[((y * w) + x) * nc + 2] = row.at(x).b;
        }
    }

    // sort by column (green)
    for (int x = 0; x < w; x++) {
        std::vector<pixel> col;
        for (int y = 0; y < h; y++) {
            pixel p;
            p.x = x;
            p.y = y;
            p.r = data[((y * w) + x) * nc];
            p.g = data[((y * w) + x) * nc + 1];
            p.b = data[((y * w) + x) * nc + 2];
            col.push_back(p);
        }

        std::sort(col.begin(), col.end(),
                  [](const pixel &a, const pixel &b) { return a.g < b.g; });

        for (int y = 0; y < h; y++) {
            data[((y * w) + x) * nc] = col.at(x).r;
            data[((y * w) + x) * nc + 1] = col.at(x).g;
            data[((y * w) + x) * nc + 2] = col.at(x).b;
        }
    }
}