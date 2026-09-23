#pragma once
#include "components.hpp"
#include "entityid.hpp"
#include "sparseset.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

class Game{
    private:
        SparseSet<Velocity> velocitys;
        SparseSet<Collider> colliders;
        SparseSet<AI> ais; 
        SparseSet<Target> targets;

        EntityID player;
        EntityID nextId = 0;
        SDL_Renderer* ren;



    public:
        Game(SDL_Renderer* ren);
        void update();
        void process();
        EntityID spawn();
        EntityID spawn(float x, float y);
        void draw();
};