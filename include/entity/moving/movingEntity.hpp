#pragma once
#include "entity/entity.hpp"

class MovingEntity : public Entity{
    public:
        MovingEntity(float x, float y, float w, float h, float speed);
        void move();
    
    protected:
        float speed;
};