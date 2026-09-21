#include "systeme/sparseset.hpp"
#include "entityid.hpp"

template<typename T>
template<typename... Args>
void SparseSet<T>::add(EntityID id, Args&&... args){
    sparse[id] = data.size();
    toEntitys.push_back(id);
    data.emplace_back(std::forward<Args>(args)...);

}

template<typename T>
void SparseSet<T>::remove(EntityID id){

    data[sparse[id]]= data[data.size()-1];
    data.pop_back();

    toEntitys[sparse[id]] = toEntitys[toEntitys.size()-1];
    toEntitys.pop_back();

    sparse[toEntitys[toEntitys.size()-1]] = sparse[id];
    sparse.erase(id);
}