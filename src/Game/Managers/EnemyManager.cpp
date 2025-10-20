//
// Created by iris on 16/10/2025.
//

#include "EnemyManager.h"

void EnemyManager::UpdateEnemies(float deltaTime) {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].Update(deltaTime);
    }
    //TODO: Check for deads
}

void EnemyManager::DrawEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].Draw();
    }
}


void EnemyManager::DestroyEnemy() {
//TODO: unload enemy and add score
}

void EnemyManager::SpawnNewEnemy() {
    //TODO: spawner
}








