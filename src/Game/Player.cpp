//
// Created by iris on 13/10/2025.
//

#include "Player.h"
#include <raymath.h>

#include "GlobalGameDefines.h"

constexpr float Player::MAX_SPEED;
constexpr int Player::MAX_HEALTH;

Player::Player() {
    SetPlayerPosition(Vector2{0.0f, 0.0f});
    health = MAX_HEALTH;
    SetPlayerSpeed(Vector2 {0.0f,0.0f});
    LoadResources();
}


Player::~Player() {
    UnloadResources();
}

void Player::Update(float deltaTime) {
    EvaluateInput();
    SetPlayerPosition(position + speed * deltaTime);
}

void Player::Draw() {
    DrawTexture(playerTexture, position.x, position.y, WHITE);
    //DEBUGGIN draw collider box in top of player
    if (IsKeyDown(KEY_G)) {
        DrawRectangleLines(
        (int)collisionBox.x,
        (int)collisionBox.y,
        (int)collisionBox.width,
        (int)collisionBox.height,
        RED);
    }
}

void Player::SetPlayerPosition(Vector2 pos) {
    //Clamp position to the inside the gameplay area
    pos.x = Clamp(pos.x, GameGlobalVar::gameplayLeftBorder,  GameGlobalVar::gameplayRightBorder);
    pos.y = Clamp(pos.y, GameGlobalVar::gameplayTopBorder, GameGlobalVar::gameplayBottomBorder);
    position = pos;
    collisionBox.x = position.x;
    collisionBox.y = position.y;
}

void Player::SetPlayerSpeed(Vector2 speed) {
    this->speed = speed;
}

void Player::EvaluateInput() {

    //Evaluate direction
    Vector2 dir = {0.0f, 0.0f};
    bool right  = IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D);
    bool left = IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A);
    bool up = IsKeyDown(KEY_UP) || IsKeyDown(KEY_W);
    bool down = IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S);

    if (right && !left) dir.x = 1.0f;
    if (left && !right) dir.x = -1.0f;
    if (up && !down) dir.y = -1.0f;
    if (down && !up) dir.y = 1.0f;

    if (dir.x != 0.0f || dir.y != 0.0f) {
        dir = Vector2Normalize(dir);
    }

    speed = dir * MAX_SPEED;

}



void Player::LoadResources() {
    playerTexture = LoadTexture("resources/Game/Player.png");
    // Scale collider to the texture size
    collisionBox.width = playerTexture.width;
    collisionBox.height = playerTexture.height;
    fxImpact = LoadSound("resources/Sounds/PlayerImpact.mp3");
    fxShoot = LoadSound("resources/Sounds/Shoot.mp3");
}

void Player::UnloadResources() {
    UnloadTexture(playerTexture);
    UnloadSound(fxImpact);
    UnloadSound(fxShoot);
}

void Player::TakeDamage(int damage) {
    //Play sound and reduce health
    PlaySound(fxImpact);
    health -= damage;
}
