//
// Created by iris on 26/10/2025.
//

#include "HealthContainer.h"


void HealthContainer::Init() {
    heartTexture = LoadTexture("resources/Game/LivesIcon.png");
}

void HealthContainer::Unload() {
    UnloadTexture(heartTexture);
}

void HealthContainer::Draw(int playerHealth) {
    Vector2 position = POSITION;

    //Draw one heart for each player live, displaced by an offset
    for (int i = 0; i < playerHealth; i++) {
        DrawTexture(heartTexture, position.x, position.y, WHITE);
        position.x += OFFSET.x;
    }
}

