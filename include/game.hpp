#pragma once
#include "components.hpp"
#include "entityid.hpp"
#include "systems/sparseset.hpp"

class Game{
    private:
        SparseSet<Velocity> velocitys;
        SparseSet<Collider> colliders;
        SparseSet<AI> ais; 
        SparseSet<Target> targets;

        EntityID player;

        EntityID nextId = 0;


    public:
        void update();
        void spawn();
        void draw();
};