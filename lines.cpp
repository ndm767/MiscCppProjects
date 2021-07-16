#include <SDL2/SDL.h>

void drawLines(SDL_Renderer *rend, int w, int h, int len, float angle)
{
    angle /= 1000.0f;
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    for (int x = len; x < w; x += 2 * len)
    {
        for (int y = len; y < h; y += 2 * len)
        {
            SDL_RenderDrawLine(rend, x + cos(angle) * len, (y) + sin(angle) * len, x - cos(angle) * len, (y)-sin(angle) * len);
        }
    }
}

int main(int argc, char *argv[])
{

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Lines", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;

    while (running)
    {
        SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_RenderClear(rend);

        int twopi = 6282;
        drawLines(rend, 400, 400, 10, SDL_GetTicks() % twopi);

        SDL_RenderPresent(rend);

        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }
            else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                running = false;
            }
        }
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}