#include <SDL3/SDL.h>
#include "entity/entity.hpp"
#include "map/map.hpp"
#include <SDL3/SDL_power.h>
#include <SDL3/SDL_render.h>
#include <iostream>

int main() {
    SDL_Window* win = SDL_CreateWindow("Fenêtre", 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ren = SDL_CreateRenderer(win, nullptr);

    Map map(ren, "res/image.png");

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }
        SDL_SetRenderDrawColor(ren, 0,255,255,255);
        SDL_RenderClear(ren);

        map.render(ren, 0,0);

        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}