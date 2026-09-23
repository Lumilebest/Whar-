#pragma once
#include "components.hpp"
#include "entityid.hpp"
#include "sparseset.hpp"

void processAI(EntityID id, SparseSet<AI>* ais, SparseSet<Velocity>* velocitys, SparseSet<Collider>* colliders, SparseSet<Target>* targets);