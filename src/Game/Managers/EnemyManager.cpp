//
// Created by iris on 16/10/2025.
//

#include "EnemyManager.h"

#include <cstdlib>

#include "Game/Enemies/Enemy2.h"
#include "Game/Enemies/Enemy3.h"

void EnemyManager::Update(float deltaTime) {
    // Check for new spawns
    CheckForNewSpawn(deltaTime);

    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->Update(deltaTime);
    }
    //TODO: Check for deads
}

void EnemyManager::DrawEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->Draw();
    }
}

void EnemyManager::CheckForNewSpawn(float deltaTime) {
    //This method updates the spawn clock
    spawnTimer -= deltaTime;

    if (spawnTimer < 0) {
        SpawnNewEnemy();
    }
}


void EnemyManager::DestroyEnemy() {
//TODO: unload enemy and add score
}

void EnemyManager::SpawnNewEnemy() {
    // If the boss already spawned don't spawn more enemies
    if (isBossSpawn) {
        return;
    }

    // Throw a die to select a random enemy
    int dice = rand() % 100;
    BaseEnemy* newEnemy = nullptr;

    if (dice < 50) {
        newEnemy = new Enemy1();
    }else if (dice < 80) {
        newEnemy = new Enemy2();
    }else if (dice < 100) {
        newEnemy = new Enemy3();
    }

    if (newEnemy!=nullptr) {
        newEnemy->EnemyInit();
        enemies.push_back(newEnemy);
    }
}








