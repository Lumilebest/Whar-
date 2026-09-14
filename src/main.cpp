#include <SDL3/SDL.h>
#include "entity/moving/movingEntity.hpp"
#include "map/map.hpp"
#include <SDL3/SDL_power.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <iostream>

int main() {
    SDL_Window* win = SDL_CreateWindow("Fenêtre", 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ren = SDL_CreateRenderer(win, nullptr);


    MovingEntity e1 = MovingEntity(50,50,10,10,5);

    bool running = true;
    SDL_Event event;

    Uint64 lastTime = SDL_GetTicks();

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }

        Uint64 time = SDL_GetTicks();
        if (time - lastTime >= 200){
            e1.move();
            lastTime = time;
        }


        SDL_SetRenderDrawColor(ren, 0,255,255,255);
        SDL_RenderClear(ren);
        e1.draw(ren);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}