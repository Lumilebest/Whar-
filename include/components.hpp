#pragma once
#include "entityid.hpp"
#include <SDL3/SDL_rect.h>
#include <glm/glm.hpp>

enum IAType{
    Rusher
};

struct Component{
    EntityID id;
};

struct Collider:Component{
    SDL_FRect collider;
    Collider(EntityID id, float x, float y, float w, float h)
        : Component{id}, collider{x, y, w, h} {}
};

struct Velocity:Component{
    float speed;
    glm::vec2 direction;
    Velocity(EntityID id, float speed, float dx, float dy)
        : Component{id}, speed(speed), direction{dx, dy} {}
};

struct Target: Component{
    EntityID target;
    Target(EntityID id, EntityID target)
        : Component{id}, target(target) {}
};

struct AI:Component{
    IAType type;
    AI(EntityID id, IAType type)
        : Component{id}, type(type) {}
};

