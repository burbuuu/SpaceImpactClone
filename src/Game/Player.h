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
    Player(Vector2 postion, BulletManager& bullet_manager);
    ~Player();
    void Update(float deltaTime);
    void Draw();

    inline int GetHealth() { return health; }
    void SetPlayerPosition(Vector2 position);
    void SetPlayerSpeed(Vector2 speed);
    void TakeDamage(int damage);
    void Shoot();
    Rectangle GetCollider() const {return collisionBox;};

private:
    Vector2 position;
    Vector2 speed{};
    int health{};

    //Bullet manager reference
    BulletManager& bulletManager;

    //Texture
    Texture2D   playerTexture{};
    // Collision box
    Rectangle collisionBox{};

    //Sounds
    Sound fxImpact;
    Sound fxShoot;

    // static constants
    static constexpr int MAX_HEALTH = 3;
    static constexpr float MAX_SPEED = 300.0f;
    const Vector2 SHOOT_OFFSET {105,35}; // Width and half the height of the player texture

    void EvaluateInput();
    void LoadResources();
    void UnloadResources();
};


#endif //SPACEIMPACT_PLAYER_H