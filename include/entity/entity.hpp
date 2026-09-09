#include <SDL3/SDL.h>
#pragma once

class Entity {
public:
    Entity();
    bool entityCollide(Entity);
private:
    SDL_FPoint position;
    SDL_FPoint size;
};