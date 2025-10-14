//
// Created by iris on 13/10/2025.
// Definitions for the player
//

#ifndef SPACEIMPACT_PLAYER_H
#define SPACEIMPACT_PLAYER_H
#include <raylib.h>



class Player {
public:
    Player();
    ~Player();
    void Update(float deltaTime);
    void Draw();

    void SetPlayerPosition(Vector2 position);
    void SetPlayerSpeed(Vector2 speed);
    void TakeDamage(int damage);
    void Shoot();

private:

    Vector2 position{};
    Vector2 speed{};
    int health{};

    //Texture
    Texture2D   playerTexture{};

    //Sounds
    Sound fxImpact;
    Sound fxShoot;

    static constexpr int MAX_HEALTH = 3;
    static constexpr float SPEED = 1.0f;

    void LoadResources();
    void UnloadResources();
};


#endif //SPACEIMPACT_PLAYER_H