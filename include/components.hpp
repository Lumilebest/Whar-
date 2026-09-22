#pragma once
#include "entityid.hpp"
#include <SDL3/SDL_rect.h>
#include <glm/glm.hpp>



struct Component{
    EntityID id;
};

struct Collider:Component{
    SDL_FRect collider;
};

struct Velocity:Component{
    float speed;
    glm::vec2 direction;
};



enum IAType{
    Rusher
};

struct AI:Component{
    IAType type;
};

