#pragma once
#include "entity/entity.hpp"
#include <vector>

class Wave{
    public:
        ~Wave();
        void play();
        

    private:
        std::vector<Entity*> entities;
};      