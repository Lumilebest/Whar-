#include "map/Map.hpp"
#include <SDL3_image/SDL_image.h>

Map::Map(SDL_Renderer* ren, const char* path){
    SDL_Surface* surf = IMG_Load(path);
    
    width = static_cast<float>(surf->w);
    height = static_cast<float>(surf->h);

    texture = SDL_CreateTextureFromSurface(ren, surf);
    SDL_DestroySurface(surf);
}

Map::~Map(){
    if(texture) SDL_DestroyTexture(texture);
}

void Map::render(SDL_Renderer* ren, float x, float y){
    SDL_FRect dst = { x,y,width,height};
    SDL_RenderTexture(ren, texture, nullptr, &dst);
}