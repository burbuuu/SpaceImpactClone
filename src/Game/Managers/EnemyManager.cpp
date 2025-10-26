//
// Created by iris on 16/10/2025.
//

#include "EnemyManager.h"

#include "Game/GlobalGameDefines.h"
#include "Game/Enemies/Boss.h"

void EnemyManager::Init() {
    //Reset boss data
    isBossSpawn = false;
    ClearEnemies();
}


void EnemyManager::Update(float deltaTime) {
    // Check for new spawns
    CheckForNewSpawn(deltaTime);

    //Update each enemy and check if they are out of bounds
    std::vector<BaseEnemy*> toDestroy;
    for (auto* enemy : enemies) {
        enemy->Update(deltaTime);
        if (enemy->GetPosition().x < GameGlobalVar::gameplayLeftBorder - 40) {
            toDestroy.push_back(enemy);
        }
    }

    //Destroy out of bounds enemies
    for (auto enemy : toDestroy) {
        DestroyEnemy(enemy);
    }
}

void EnemyManager::DrawEnemies() {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->Draw();
    }
}

void EnemyManager::DrawDebug() {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->DrawDebug();
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


void EnemyManager::DestroyEnemy(BaseEnemy *enemy) {
    auto it = std::find(enemies.begin(), enemies.end(), enemy);
    if (it != enemies.end()) {
        delete *it; // free heap memory
        enemies.erase(it); // remove from vector
    }
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

void EnemyManager::SpawnBoss(BulletManager &bulletManager) {
    boss = new Boss(bulletManager);

    if (boss != nullptr) {
        boss->EnemyInit();
        enemies.push_back(boss);
        isBossSpawn = true;
    } else {
        TraceLog(1,"Boss failed to be instantiated.");
    }
}

void EnemyManager::ClearEnemies() {
    for (auto enemy: enemies) {
        enemy->UnloadResources();
        DestroyEnemy(enemy);
    }
}