//
// Created by iris on 16/10/2025.
//

#ifndef SPACEIMPACT_ENEMY_H
#define SPACEIMPACT_ENEMY_H
#include <raylib.h>


class BaseEnemy {
public:
    virtual ~BaseEnemy();
    virtual void EnemyInit();
    void Update(float deltaTime);
    void Draw();
    void UnloadResources();
    int GetHealth(){return health;}
    int GetScore(){return givenScore;}
    virtual void TakeDamage(int amount);
    Vector2 GetPosition(){return position;}

    Rectangle GetCollider(){return boxCollider;};
    void DrawDebug();



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