#include "entity/Entity.hpp"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

Entity::Entity(float x, float y, float w, float h)
    : rect({x,y,w,h}) {
}

bool Entity::collide(const Entity* e){
    return SDL_HasRectIntersectionFloat(&rect, &e->rect);
}

void Entity::drawCollide(SDL_Renderer* ren){
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_RenderFillRect(ren, &rect);
}

float Entity::getX(){
    return rect.x;
}
float Entity::getY(){
    return rect.y;
}
float Entity::getW(){
    return rect.w;
}
float Entity::getH(){
    return rect.h;
}


void Entity::setX(float x){
    rect.x = x;
}
void Entity::setY(float y){
    rect.y = y;
}
void Entity::setW(float w){
    rect.w = w;
}
void Entity::setH(float h){
    rect.h = h;
}