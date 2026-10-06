#include <SDL3/SDL.h>
#include <iostream>

int main(){
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "erreur SDL_INIT_VIDEO\n";
        return 1;
    }
    SDL_Window* window; SDL_Renderer* renderer;

    if (!SDL_CreateWindowAndRenderer("whar?", 920, 920, SDL_WINDOW_RESIZABLE, &window, &renderer)){
        std::cout << "erreur CREATEWINDOW\n";
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderVSync(renderer, 0);

    bool running = true;
    while (running){
        SDL_Event e;
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_EVENT_QUIT) running = false;
        }
        SDL_SetRenderDrawColor(renderer, 20, 20, 30, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}