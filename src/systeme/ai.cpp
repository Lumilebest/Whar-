#include "systems/ai.hpp"
#include "components.hpp"
#include "sparseset.hpp"
#include <glm/glm.hpp>
#include <iostream>

void processAI(EntityID id, SparseSet<AI>* ais, SparseSet<Velocity>* velocitys, SparseSet<Collider>* colliders, SparseSet<Target>* targets){
    switch (ais->get(id)->type){
        case Rusher:
            Velocity* act = velocitys->get(id);
            glm::vec2 temp = {colliders->get(targets->get(id)->target)->collider.x- colliders->get(id)->collider.x,
                             colliders->get(targets->get(id)->target)->collider.y -colliders->get(id)->collider.y};
            if (glm::length(temp) > 0.0f){
                act->direction = temp;
            }
            std::cout << "erreur processAi\n";
            break;
    }
}