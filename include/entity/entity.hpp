#include <SDL3/SDL.h>
#pragma once

class Entity {
public:
    Entity();
    Entity(float x,float y,float w,float h);
    ~Entity();
    bool collide(Entity& e2);
    void draw(SDL_Renderer* renderer);
    void setX(float x);
    void setY(float y); 

protected:
    SDL_FRect rect;
};