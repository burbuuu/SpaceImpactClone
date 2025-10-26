//
// Created by iris on 13/10/2025.
// Definitions for the player
//

#ifndef SPACEIMPACT_PLAYER_H
#define SPACEIMPACT_PLAYER_H
#include <raylib.h>

#include "Managers/BulletManager.h"


class Player {
public:
    Player(BulletManager& bullet_manager);
    void InitPlayer();
    void Update(float deltaTime);
    void Draw();
    void DrawDebug();
    void UnloadResources();

    inline int GetHealth() { return health; }
    void SetPlayerPosition(Vector2 position);
    void SetPlayerSpeed(Vector2 speed);
    void TakeDamage(int damage);
    void Shoot();
    Rectangle GetCollider() const {return collisionBox;};
    bool IsPlayerInvulnerable() {return invulnerabilityTimer > 0;}

private:
    Vector2 position;
    Vector2 speed{};
    int health{};
    float shootTimer;
    float invulnerabilityTimer = 0.0f;
    float const invulnerabilityDuration = 1.3f;


    //Bullet manager reference
    BulletManager& bulletManager;

    //Texture
    Texture2D   playerTexture{};
    // Collision box
    Rectangle collisionBox{};

    //Sounds
    Sound fxImpact;
    Sound fxShoot;

    //  constants
    const Vector2 START_POSITION {0,GameGlobalVar::screenHeight/2};
    static constexpr int MAX_HEALTH = 3;
    static constexpr float MAX_SPEED = 300.0f;
    const Vector2 SHOOT_OFFSET {105,35}; // Width and half the height of the player texture
    const float SHOOT_TIME = 0.5f;

    void EvaluateInput();
    void LoadResources();

};


#endif //SPACEIMPACT_PLAYER_H