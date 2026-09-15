#include "wave/wave.hpp"
#include "entity/entity.hpp"
#include "entity/moving/movingEntity.hpp"

Wave::~Wave(){
    for (Entity* e : entities){
        delete e;
    }
}

void Wave::play(){
    entities.push_back(new MovingEntity(20,10,10,10,0.002));
}