#pragma once
#include <entt/entt.hpp>
#include <entt/entity/fwd.hpp>
#include <iostream>
#include "component.hpp"
#include "systems/direction/toEnemyDirection.hpp"
#include "systems/move.hpp"

inline void computAI(auto id ,entt::registry* registry, float delta){
    switch(registry->get<AI>(id).type){
        case Rusher:
            toEnemyDirection(id, registry);
            moveEntity(id, registry, delta);
            break;
        default:
            std::cout << "error pas de type AI\n";
    }
};