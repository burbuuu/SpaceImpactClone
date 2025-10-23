//
// Created by iris on 16/10/2025.
//

#include "BaseEnemy.h"
#include "../GlobalGameDefines.h"

BaseEnemy::~BaseEnemy() {
    UnloadResources();
}


void BaseEnemy::EnemyInit() {
    GenerateRandomSpawnPositions();
    boxCollider = {position.x, position.y,size.x,size.y};
    LoadSound("resources/Sounds/EnemyImpact.mp3");
}


void BaseEnemy::Draw() {
    DrawTexture(enemyTexure, position.x, position.y, WHITE);
}

void BaseEnemy::Update(float deltaTime) {
    position.x -= speed *deltaTime;
    //Update collider position
    boxCollider.x = position.x;
}

void BaseEnemy::TakeDamage(int amount) {
    //Reduce health and play sound
    health -= amount;
    TraceLog(1,"Enemy has been hit");
    //PlaySound(hitSound);
}

void BaseEnemy::UnloadResources() {
    UnloadTexture(enemyTexure);
    UnloadSound(hitSound);
}

void  BaseEnemy::GenerateRandomSpawnPositions() {
    position.y = GetRandomValue(GameGlobalVar::gameplayTopBorder, GameGlobalVar::gameplayBottomBorder);
    position.x = GameGlobalVar::gameplayRightBorder + 40;
}

