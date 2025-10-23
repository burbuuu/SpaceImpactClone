//
// Created by iris on 23/10/2025.
//


#include "Enemy3.h"

void Enemy3::EnemyInit() {
    BaseEnemy::EnemyInit();
    enemyTexure = LoadTexture("resources/Game/Enemy3.png");
    size = Vector2 {88, 50};
    health = 3;
    speed = 350;
    givenScore = 60;
}