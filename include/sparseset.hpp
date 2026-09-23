#pragma once
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
        void add(EntityID id, Args&&... args){
            sparse[id] = data.size();
            data.emplace_back(id, std::forward<Args>(args)...);
        }

        void remove(EntityID id){
            data[sparse[id]] = data[data.size()-1];
            sparse[data[data.size()-1].id] = sparse[id];
            data.pop_back();
            sparse.erase(id);
        }

        void clear(){
            sparse.clear();
            data.clear();
        }

        std::unordered_map<EntityID, size_t>* getSparse(){
            return &sparse;
        }

        T* get(EntityID id){
            return &data[sparse[id]];
        }

        void set(EntityID id, T dat){
            data[sparse[id]] = dat;
        }
};