#include <SDL3/SDL.h>
#include "entity/entity.hpp"
#include <iostream>

int main() {
    SDL_Window* window = SDL_CreateWindow("Fenêtre", 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    Entity e1;
    Entity e2;

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }

        SDL_SetRenderDrawColor(renderer, 30, 30, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        if (e1.entityCollide(e2)){
            std::cout << "oui";
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}