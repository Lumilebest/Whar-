#include "world.hpp"
#include "component.hpp"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include "systems/computeai.hpp"
#include "systems/move.hpp"

World::World(SDL_Renderer* ren, Uint64 time): ren(ren), time(time), lastTime(time), lastTimeSpawn(time){
    player = registry.create();
    registry.emplace<Collider>(player, SDL_FRect{500,500,15,15});
}
       
void World::update(){
    time = SDL_GetTicks();
    delta = time-lastTime;
    createEntity();
    comput();
    lastTime = time;
}

void World::comput(){
    for (auto id : registry.view<Velocity>()){
        computAI(id, &registry, delta);
    }
}


void World::drawCollide(){
    for (auto id: registry.view<Collider>()){
        SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
        SDL_RenderRect(ren, &registry.get<Collider>(id).rect);
    }
}

void World::createEntity(){
    if ( time - lastTimeSpawn >= 5000 ){
        auto id = registry.create();
        registry.emplace<Collider>(id,SDL_FRect{0,0,10,10});
        registry.emplace<Velocity>(id, 10.0f, glm::vec2{0,0});
        registry.emplace<AI>(id, Rusher);
    }
}