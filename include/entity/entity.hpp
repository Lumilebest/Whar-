#include <SDL3/SDL.h>
#pragma once

class Entity {
public:
    Entity();
    Entity(float x,float y,float w,float h);
    bool collide(Entity& e2);
    void draw(SDL_Renderer* renderer);

private:
    SDL_FRect rect;
};