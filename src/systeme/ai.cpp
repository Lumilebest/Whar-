#include "systems/ai.hpp"
#include "components.hpp"
#include "systems/sparseset.hpp"
#include <iostream>

void process(EntityID id, SparseSet<AI> ais, SparseSet<Velocity> velocitys, SparseSet<Collider> colliders){
    switch (ais.get(id).id){
        case Rusher:
            
        default:
            std::cout << "erreur id IA\n";
            break;
    }
}