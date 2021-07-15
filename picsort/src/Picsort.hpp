#pragma once

#include <string>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class Picsort {
public:
    Picsort(std::string path);
    ~Picsort();

    void run();

protected:
    void sort();

    int w, h, nc;
    unsigned char *data;

    bool running;

    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
};