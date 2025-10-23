//
// Created by iris on 16/10/2025.
//

#include "BaseEnemy.h"
#include "../GlobalGameDefines.h"

void BaseEnemy::EnemyInit() {
    GenerateRandomSpawnPositions();
    LoadSound("Sounds/EnemyImpact.mp3");
}


void BaseEnemy::Draw() {
    DrawTexture(enemyTexure, position.x, position.y, WHITE);
}

void BaseEnemy::Update(float deltaTime) {
    position.x -= speed *deltaTime;

    // TODO: check for hits
}

void BaseEnemy::UnloadEnemy() {
    UnloadTexture(enemyTexure);
    UnloadSound(hitSound);
}

void  BaseEnemy::GenerateRandomSpawnPositions() {
    position.y = GetRandomValue(GameGlobalVar::gameplayTopBorder, GameGlobalVar::gameplayBottomBorder);
    position.x = GameGlobalVar::gameplayRightBorder + 40;
}

