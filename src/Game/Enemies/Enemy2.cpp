//
// Created by iris on 20/10/2025.
//

#include "Enemy2.h"

void Enemy2::EnemyInit() {
    BaseEnemy::EnemyInit();
    enemyTexure = LoadTexture("Resources/Game/Enemy2.png");
    size = Vector2 {60, 69};
    health = 2;
    speed = 300;
    givenScore = 50;

}