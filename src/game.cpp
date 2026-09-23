#include "game.hpp"
#include "build.hpp"
#include "entityid.hpp"

void Game::spawn(){
    const BuildData spawnData = getBuild(Zombie);
    EntityID id = nextId++;

    colliders.add(id, spawnData.collider.collider.x, spawnData.collider.collider.y, spawnData.collider.collider.w, spawnData.collider.collider.h);
    velocitys.add(id, spawnData.velocity.speed, spawnData.velocity.direction.x, spawnData.velocity.direction.y);
    targets.add(id, player);
    ais.add(id, spawnData.aiType);
}

void Game::draw(){
    for (auto [id, index] : *colliders.getSparse()){
        
    }
}

void Game::update(){
    spawn();
    draw();
}