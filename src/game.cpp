#include "game.hpp"
#include "build.hpp"
#include "entityid.hpp"
#include "systems/ai.hpp"
#include <SDL3/SDL_render.h>
#include "systems/velocity.hpp"

Game::Game(SDL_Renderer* ren):ren(ren){
    player = spawn(100.0f,100.0f);
}

EntityID Game::spawn(float x, float y){
    const BuildData spawnData = getBuild(Zombie);
    EntityID id = nextId++;

    colliders.add(id, x, y, spawnData.collider.collider.w, spawnData.collider.collider.h);
    velocitys.add(id, spawnData.velocity.speed, spawnData.velocity.direction.x, spawnData.velocity.direction.y);
    targets.add(id, player);
    ais.add(id, spawnData.aiType);
    return id;
}

EntityID Game::spawn(){
    const BuildData spawnData = getBuild(Zombie);
    EntityID id = nextId++;

    colliders.add(id, spawnData.collider.collider.x, spawnData.collider.collider.y, spawnData.collider.collider.w, spawnData.collider.collider.h);
    velocitys.add(id, spawnData.velocity.speed, spawnData.velocity.direction.x, spawnData.velocity.direction.y);
    targets.add(id, player);
    ais.add(id, spawnData.aiType);
    return id;
}

void Game::process(){
    for (auto [id, index] : *ais.getSparse()){
        processAI(id, &ais, &velocitys, &colliders, &targets);
        processVelocity(id, &velocitys, &colliders);
    }
}

void Game::draw(){
    for (auto [id, index] : *colliders.getSparse()){
        SDL_SetRenderDrawColor(ren, 0,0,255,255);
        SDL_RenderRect(ren, &colliders.get(id)->collider);
    }
}


void Game::update(){
    spawn();
    process();
    draw();
}