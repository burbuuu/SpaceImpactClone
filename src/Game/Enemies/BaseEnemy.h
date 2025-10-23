//
// Created by iris on 16/10/2025.
//

#ifndef SPACEIMPACT_ENEMY_H
#define SPACEIMPACT_ENEMY_H
#include <raylib.h>


class BaseEnemy {
    public:
    virtual void EnemyInit();
    void Update(float deltaTime);
    void Draw();
    void UnloadEnemy();
    int GetEnemyHealth(){return health;};



protected:
    void GenerateRandomSpawnPositions();

    int health;
    int speed;
    int givenScore;
    Sound hitSound;
    Texture2D enemyTexure;
    Vector2 position;
    Vector2 size;
    Rectangle boxCollider;

};


#endif //SPACEIMPACT_ENEMY_H