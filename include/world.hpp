#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <entt/entity/fwd.hpp>
#include <entt/entt.hpp>

class World{
    private:
        entt::registry registry;
        SDL_Renderer* ren;
        Uint64 time;
        Uint64 lastTime;
        Uint64 lastTimeSpawn;
        Uint64 delta;
        entt::entity player;

    public:
        World(SDL_Renderer* ren, Uint64 time);
        void update();
        void comput();
        void drawCollide();
        void createEntity();
};