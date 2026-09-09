#include "entity/entity.hpp"
#include <iostream>
#include <SDL3/SDL.h>

Entity::Entity(){
    position = {100.0f, 100.0f};
    size = {50.0f, 50.0f};
}

bool Entity::entityCollide(Entity e2){
    return this->position.x < e2.position.x+e2.size.x && this->position.x+this->size.x>e2.position.x && this->position.y<e2.position.y+e2.size.y && this->position.y+this->size.y>e2.position.y;
}
