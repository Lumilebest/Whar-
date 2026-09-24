#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <entt/entity/fwd.hpp>
#include <entt/entt.hpp>

class World{
    private:
        entt::registry registry;
        SDL_Renderer* ren;
    public:
        World(SDL_Renderer* ren);
        void update();
        void draw();
        void createEntity();
};