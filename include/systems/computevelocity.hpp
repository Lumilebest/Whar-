#pragma once
#include "component.hpp"
#include <entt/entity/fwd.hpp>
#include <entt/entt.hpp>
#include <glm/ext/vector_float2.hpp>
#include <glm/geometric.hpp>

inline void toEnemyDirection(auto id, entt::registry* registry){
    Collider* rect = &registry->get<Collider>(id);
    Collider* rectTarget = &registry->get<Collider>(registry->get<Target>(id).id);
    
    glm::vec2 dir = {
        rectTarget->rect.x - rect->rect.x,
        rectTarget->rect.y - rect->rect.y 
    };
    if ( glm::length(dir)!=0 ){
        dir = glm::normalize(dir);
    }
    
    Velocity* v = &registry->get<Velocity>(id);
    v->direction = dir;
}