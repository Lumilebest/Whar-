#include "components.hpp"
#include "game.hpp"
#include "sparseset.hpp"
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

    bool running = true;
    SDL_Event event;

    Game game(ren);

    SparseSet<Velocity> velocitys;
    SparseSet<Collider> colliders;
    SparseSet<AI> ais;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }

        game.update();

        SDL_SetRenderDrawColor(ren, 0,255,0,255);
        SDL_RenderClear(ren);

        game.draw();

        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}