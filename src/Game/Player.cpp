//
// Created by iris on 13/10/2025.
//

#include "Player.h"

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
    //TODO
}
void Player::Draw() {
    DrawTexture(playerTexture, position.x, position.y, WHITE);
}

void Player::LoadResources() {
    playerTexture = LoadTexture("resources/Game/Player.png");
    fxImpact = LoadSound("resources/Sounds/PlayerImpact.mp3");
    fxShoot = LoadSound("resources/Sounds/Shoot.mp3");
}

void Player::UnloadResources() {
    UnloadTexture(playerTexture);
    UnloadSound(fxImpact);
    UnloadSound(fxShoot);
}

void Player::SetPlayerPosition(Vector2 pos) {
    // TODO constrain player postion
    position = pos;
}

void Player::SetPlayerSpeed(Vector2 speed) {
    //TODO Check for a valid speed
    this->speed = speed;
}

void Player::TakeDamage(int damage) {
    //Play sound and reduce health
    PlaySound(fxImpact);
    health -= damage;
    //Check for death
    if (health <= 0) {
        //TODO
    }
}
