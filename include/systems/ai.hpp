#pragma once
#include "components.hpp"
#include "entityid.hpp"
#include "systems/sparseset.hpp"

void process(EntityID id, SparseSet<AI> ais, SparseSet<Velocity> velocitys, SparseSet<Collider> colliders);