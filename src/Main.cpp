#include "components.hpp"
#include "systems/sparseset.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_power.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_timer.h>

int main() {
    SDL_Window* win = SDL_CreateWindow("Fenêtre", 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* ren = SDL_CreateRenderer(win, nullptr);


    SDL_FPoint mouse;

    bool running = true;
    SDL_Event event;

    Uint64 lastTime = SDL_GetTicks();
    Uint64 time;
    float delta = 0.0f;


    SparseSet<Velocity> velocitys;
    SparseSet<Collider> colliders;
    SparseSet<AI> ais;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }
        time = SDL_GetTicks();
        delta = (time-lastTime)/1000.0f;

        SDL_GetMouseState(&mouse.x, &mouse.y);

        SDL_SetRenderDrawColor(ren, 0,255,0,255);
        SDL_RenderClear(ren);

        SDL_RenderPresent(ren);
        lastTime = time;
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}