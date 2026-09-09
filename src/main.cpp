#include <SDL3/SDL.h>
#include "entity/entity.hpp"
#include <SDL3/SDL_power.h>
#include <SDL3/SDL_render.h>
#include <iostream>

int main() {
    SDL_Window* window = SDL_CreateWindow("Fenêtre", 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    Entity e1;
    Entity e2(0,0,1000,1000);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 0,255,255,255);
        SDL_RenderClear(renderer);
        e1.draw(renderer);
        e2.draw(renderer);
        SDL_RenderPresent(renderer);
        if (e1.collide(e2)){
            std::cout << "oui";
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}