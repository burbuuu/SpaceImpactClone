//
// Created by iris on 24/10/2025.
//

#include "Boss.h"

#include <raymath.h>


Boss::Boss(BulletManager &bulleManager) : bulletManager(bulleManager){
}



void Boss::EnemyInit() {
    type = BOSS;
    position.y = INITIAL_POS_Y;
    position.x = GameGlobalVar::gameplayRightBorder + 40;
    hitSound= LoadSound("resources/Sounds/BossImpact.mp3");
    enemyTexure = LoadTexture("resources/Game/Boss1.png");
    size = Vector2 {200, 230};
    health = 5;
    speed = 100;
    givenScore = 500;

    //Shoot timer
    shootTimer = SHOOT_TIME;
}


void Boss::Update(float deltaTime) {
    if (position.x > FINAL_POSITION) {
        position.x -= speed *deltaTime;
    } else {
        //Oscillation on the y axis
        float amplitude = 60.0f;
        float frequency = 1.5f;

        position.y = INITIAL_POS_Y + amplitude * cos(GetTime()*frequency);

    }

    //Update collider position
    boxCollider.x = position.x;
    boxCollider.y = position.y;
    boxCollider.width  = size.x;
    boxCollider.height = size.y;

    CheckForShoot(deltaTime);
}

void Boss::CheckForShoot(float deltaTime) {
    shootTimer -= deltaTime;

    if (shootTimer <= 0) {
        float randomOffsetTime =GetRandomValue(-30, 30) / 100.0f;
        shootTimer = SHOOT_TIME + randomOffsetTime;

        Shoot();
    }
}

void Boss::Shoot() {
    //Shoot
    auto shootPosition = Vector2Add(position, SHOOT_OFFSET);
    bulletManager.ShootBullet(shootPosition,false);
}




