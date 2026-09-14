#include "entity/entity.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

Entity::Entity(){
    rect = {100.0f,100.0f,50.0f,50.0f};
}

Entity::Entity(float x, float y, float w, float h){
    rect = {x,y,w,h};
}

bool Entity::collide(Entity& e2){
    return rect.x < e2.rect.x+e2.rect.w && rect.x+rect.w>e2.rect.x && rect.y<e2.rect.y+e2.rect.h && rect.y+rect.h>e2.rect.y;
}

void Entity::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderRect(renderer, &rect);
}

void Entity::setX(float x){
    rect.x = x;
}
void Entity::setY(float y){
    rect.y = y;
}

float Entity::getX(){
    return rect.x;
}
float Entity::getY(){
    return rect.y;
}