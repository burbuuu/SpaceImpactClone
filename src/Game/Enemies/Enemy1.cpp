//
// Created by iris on 20/10/2025.
//

#include "Enemy1.h"

void Enemy1::EnemyInit() {
    BaseEnemy::EnemyInit();
    enemyTexure = LoadTexture("resources/Game/Enemy1.png");
    size = Vector2 {100, 50};
    health = 2;
    speed = 300;
    givenScore = 40;

}
