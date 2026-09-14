#include <SDL3/SDL.h>
#pragma once

class Map{
public:
    Map(SDL_Renderer* ren, const char* path);
    ~Map();
    void render(SDL_Render* ren, float x=0, float y=0);
protected:
    SDL_Texture* texture;
    float width=0, height=0;
}