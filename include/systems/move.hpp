#pragma once
#include "component.hpp"
#include <SDL3/SDL_stdinc.h>
#include <entt/entity/fwd.hpp>
#include <entt/entt.hpp>

inline void moveEntity(entt::entity id ,entt::registry* registry, Uint64 delta){
    Collider* collider = &registry->get<Collider>(id); 
    Velocity* velocity = &registry->get<Velocity>(id);
    collider->rect.x = velocity->direction.x*velocity->speed*delta;
    collider->rect.y = velocity->direction.y*velocity->speed*delta;
}