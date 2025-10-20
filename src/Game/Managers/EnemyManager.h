//
// Created by iris on 16/10/2025.
//

#ifndef SPACEIMPACT_ENEMYMANAGER_H
#define SPACEIMPACT_ENEMYMANAGER_H
#include <vector>

#include <raylib.h>
#include "Game/Enemies/BaseEnemy.h"
#include "Game/Managers/GameManager.h"


class EnemyManager {
public:

    void UpdateEnemies(float deltaTime);
    void DrawEnemies();
    void SpawnNewEnemy();
    void DestroyEnemy();
private:
    std::vector<BaseEnemy> enemies;

};


#endif //SPACEIMPACT_ENEMYMANAGER_H