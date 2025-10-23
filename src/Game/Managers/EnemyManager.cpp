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

    //Update each enemy
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->Update(deltaTime);
    }
    //TODO: Check for dead enemies
}

void EnemyManager::DrawEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->Draw();
    }
}

void EnemyManager::CheckForNewSpawn(float deltaTime) {
    //This method updates the spawn clock and if necessary spawns a new enemy.
    spawnTimer -= deltaTime;

    if (spawnTimer < 0) {
        SpawnNewEnemy();
        spawnTimer = medianSpawnTime + (((rand() % 100) / 100.0f - 0.5f) * 0.4f); // Added a random offset for variation
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
    }else if (dice < 85) {
        newEnemy = new Enemy2();
    }else if (dice < 100) {
        newEnemy = new Enemy3();
    }

    if (newEnemy!=nullptr) {
        newEnemy->EnemyInit();
        enemies.push_back(newEnemy);
    }
}

std::vector<Rectangle> EnemyManager::GetColliders() const {
    std::vector<Rectangle> colliders;
    colliders.reserve(enemies.size());

    for (auto* enemy:enemies) {
        colliders.push_back(enemy->GetCollider());
    }

    return colliders;
}









