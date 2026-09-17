#pragma once
#include "entity/Entity.hpp"
#include <SDL3/SDL_rect.h>
class MovingEntity: public Entity{
    public:
        MovingEntity(float x, float y, float w, float h, float s);
        void move(float delta, const SDL_FPoint* point);
        void move(float delta, const SDL_FRect* rect);
    private:
        float speed;
};