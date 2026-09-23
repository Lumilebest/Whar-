#pragma once
#include "components.hpp"
#include <SDL3/SDL_rect.h>
#include <cstddef>

enum buildName{
    Zombie
};

struct BuildData {
    Collider collider;
    Velocity velocity;
    IAType aiType;
};

inline const BuildData& getBuild(buildName id){
    static const BuildData table[] = {
        // Zombie
        { .collider = {NULL,0, 0, 32, 32}, .velocity = {NULL, 40.0f, {0,0}}, .aiType = Rusher },
    };
    return table[static_cast<size_t>(id)];
};

