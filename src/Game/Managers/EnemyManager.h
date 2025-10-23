//
// Created by iris on 16/10/2025.
//

#ifndef SPACEIMPACT_ENEMYMANAGER_H
#define SPACEIMPACT_ENEMYMANAGER_H
#include <vector>

#include <raylib.h>
#include <cstdlib>
#include "Game/Enemies/BaseEnemy.h"
#include "Game/Enemies/Enemy1.h"
#include "Game/Enemies/Enemy2.h"
#include "Game/Enemies/Enemy3.h"
#include "Game/Managers/GameManager.h"


class EnemyManager {
public:

    void Update(float deltaTime);
    void DrawEnemies();
    void SpawnNewEnemy();
    void DestroyEnemy(BaseEnemy* enemy);
    std::vector<BaseEnemy*> &GetEnemies() {return enemies;};

private:
    void CheckForNewSpawn(float deltaTime);

    std::vector<BaseEnemy*> enemies;
    float spawnTimer = 1.0;
    const float medianSpawnTime = 0.8;
    bool isBossSpawn = false;
};


#endif //SPACEIMPACT_ENEMYMANAGER_H