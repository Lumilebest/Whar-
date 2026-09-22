#pragma once
#include "components.hpp"
#include "systems/sparseset.hpp"

class Game{
    private:
        SparseSet<Velocity> velocitys;
        SparseSet<Collider> colliders;
        SparseSet<AI> ais; 


    public:
        void update();
        void draw();
};