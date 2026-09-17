#pragma once

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
class Entity{
    protected:
        SDL_FRect rect;
    
    public:
        Entity(float x, float y, float w, float h);

        bool collide(const Entity* e);

        void drawCollide(SDL_Renderer* ren);

        void setX(float x);
        void setY(float y);
        void setW(float w);
        void setH(float h);
        
        float getX();
        float getY();
        float getW();
        float getH();
};