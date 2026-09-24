#pragma once
#include <entt/entt.hpp>
#include <entt/entity/fwd.hpp>
#include <iostream>
#include "component.hpp"
#include "systems/computevelocity.hpp"
#include "systems/move.hpp"

inline void computAI(auto id ,entt::registry* registry, Uint64 delta){
    switch(registry->get<AI>(id).type){
        case Rusher:
            toEnemyDirection(id, registry);
            moveEntity(id, registry, delta);
            break;
        default:
            std::cout << "error pas de type AI\n";
    }
};