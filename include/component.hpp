#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_rect.h>
#include <glm/ext/vector_float2.hpp>
#include <glm/glm.hpp>
#include <entt/entt.hpp>

struct Collider{
    SDL_FRect rect;
};

struct Velocity{
    float speed;
    glm::vec2 direction;
};

struct Target{
    entt::entity id;
};

enum AIType{
    Rusher
};

struct AI{
    AIType type;
};