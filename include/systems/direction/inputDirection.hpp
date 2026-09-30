#pragma once
#include "component.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_scancode.h>
#include <entt/entt.hpp>
#include <glm/detail/qualifier.hpp>
#include <glm/ext/vector_float2.hpp>
#include <glm/geometric.hpp>

inline void inputDirection(auto id, entt::registry* registry){
    const bool* keys = SDL_GetKeyboardState(nullptr);
    glm::vec2 vec = {(keys[SDL_SCANCODE_D] - keys[SDL_SCANCODE_A]),(keys[SDL_SCANCODE_S] - keys[SDL_SCANCODE_W])};
    if(glm::length(vec)>0.0f){
        vec = glm::normalize(vec);
    }
    registry->get<Velocity>(id).direction = vec;
}