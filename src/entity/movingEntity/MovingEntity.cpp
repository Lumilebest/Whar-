#include "entity/movingEntity/MovingEntity.hpp"
#include "entity/Entity.hpp"
#include <SDL3/SDL_rect.h>
#include <cmath>

MovingEntity::MovingEntity(float x, float y, float w, float h, float s)
    :Entity(x, y, w, h), speed(s){
}

void MovingEntity::move(float delta, const SDL_FPoint* point){
    SDL_FPoint vec = {point->x-rect.x-(rect.w/2), point->y-rect.y-(rect.h/2)};
    float l = std::sqrt(vec.x*vec.x+vec.y*vec.y);
    
    rect.x += (vec.x/l)*(speed)*delta;
    rect.y += (vec.y/l)*speed*delta;
}

void MovingEntity::move(float delta, const SDL_FRect* rect){
    SDL_FPoint point = {rect->x+(rect->w/2), rect->y+(rect->h/2)};
    this->move(delta, &point);
}