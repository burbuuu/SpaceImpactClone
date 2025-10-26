//
// Created by iris on 16/10/2025.
//

#ifndef SPACEIMPACT_ENEMYMANAGER_H
#define SPACEIMPACT_ENEMYMANAGER_H

#include <vector>
#include <algorithm>
#include "BulletManager.h"

#include <raylib.h>

#include "Game/Bullet.h"
#include "Game/Enemies/BaseEnemy.h"
#include "Game/Enemies/Enemy1.h"
#include "Game/Enemies/Enemy2.h"
#include "Game/Enemies/Enemy3.h"
#include "Game/Managers/GameManager.h"

// This class keeps track of enemies.

class EnemyManager {
public:

    void Init();
    void Update(float deltaTime);
    void DrawEnemies();
    void DrawDebug();
    void SpawnNewEnemy();
    void SpawnBoss(BulletManager &bulletManager);
    void DestroyEnemy(BaseEnemy* enemy);
    std::vector<BaseEnemy*> &GetEnemies() {return enemies;}
    BaseEnemy* &GetBoss() {return boss;}
    void ClearEnemies();
    bool HasBossSpawned() {return isBossSpawn;}


private:
    void CheckForNewSpawn(float deltaTime);

    std::vector<BaseEnemy*> enemies;
    BaseEnemy* boss = nullptr; // Separate pointer for the boss to keep track of it
    float spawnTimer = 1.0;
    const float medianSpawnTime = 0.8;
    bool isBossSpawn = false;
};


#endif //SPACEIMPACT_ENEMYMANAGER_H