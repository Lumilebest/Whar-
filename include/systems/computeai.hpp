#pragma once
#include <entt/entt.hpp>
#include <entt/entity/fwd.hpp>
#include <iostream>
#include "component.hpp"

void computAI(auto id ,entt::registry* registry){
    switch(registry->get<AI>(id).type){
        case Rusher:
            
        default:
            std::cout << "error pas de type AI\n";
    }
};