#include "entity/moving/movingEntity.hpp"
#include "entity/entity.hpp"

MovingEntity::MovingEntity(float x, float y, float w, float h, float speed) : Entity(x,y,w,h), speed(speed){
}

void MovingEntity::move(){
    setX(getX()+speed);
}