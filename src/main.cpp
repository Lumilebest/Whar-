#include "world.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL.h>


int main(int argc, char* argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Erreur SDL_Init: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Base SDL3", 800, 600, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    SDL_Event event;

    World world(renderer, SDL_GetTicks());

    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
        }
        world.update();

        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
        SDL_RenderClear(renderer);
        world.drawCollide();

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}