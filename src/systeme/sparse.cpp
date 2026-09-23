#include "systems/sparseset.hpp"
#include "entityid.hpp"

template<typename T>
template<typename... Args>
void SparseSet<T>::add(EntityID id, Args&&... args){
    sparse[id] = data.size();
    data.emplace_back(id, std::forward<Args>(args)...);
}

template<typename T>
void SparseSet<T>::remove(EntityID id){

    data[sparse[id]]= data[data.size()-1];
    sparse[data[data.size()-1].id] = sparse[id];
    
    data.pop_back();
    sparse.erase(id);
}

template<typename T>
std::unordered_map<EntityID, size_t>* SparseSet<T>::getSparse(){
    return &sparse;
}

template<typename T>
T* SparseSet<T>::get(EntityID id){
    return &data[sparse[id]];
}

template<typename T>
void SparseSet<T>::set(EntityID id , T dat){
    data[sparse[id]] = dat;
}

template<typename T>
void SparseSet<T>::clear(){
    sparse.clear();
    data.clear();
}