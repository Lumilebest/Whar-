#pragma once
#include <SDL3/SDL.h>

class Entity {
public:
    Entity();
    Entity(float x,float y,float w,float h);
    bool collide(Entity& e2);
    void draw(SDL_Renderer* renderer);
    void setX(float x);
    void setY(float y); 
    float getX();
    float getY();

protected:
    SDL_FRect rect;
};