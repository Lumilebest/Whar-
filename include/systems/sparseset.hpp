#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include "entityid.hpp"

template<typename T>
class SparseSet{
    private: 
        std::unordered_map<EntityID, size_t> sparse;
        std::vector<T> data;
        static const size_t INVALID = SIZE_MAX;
    
    public:
        template<typename... Args>
        void add(EntityID id, Args&&... args);
        void remove(EntityID id);
        void clear();
        T get(EntityID id);
};