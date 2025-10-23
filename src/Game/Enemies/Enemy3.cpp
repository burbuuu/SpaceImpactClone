//
// Created by iris on 23/10/2025.
//


#include "Enemy3.h"

void Enemy3::EnemyInit() {
    BaseEnemy::EnemyInit();
    enemyTexure = LoadTexture("Resources/Game/Enemy1.png");
    size = Vector2 {88, 50};
    health = 3;
    speed = 300;
    givenScore = 60;
}