//
// Created by iris on 16/10/2025.
//

#ifndef SPACEIMPACT_ENEMY_H
#define SPACEIMPACT_ENEMY_H
#include <raylib.h>

enum EnemyType {
    REGULAR = 0,
    BOSS = 1
};

class BaseEnemy {
public:
    virtual void EnemyInit();
    virtual void Update(float deltaTime);
    void Draw();
    void UnloadResources();
    int GetHealth(){return health;}
    int GetScore(){return givenScore;}
    virtual void TakeDamage(int amount);
    Vector2 GetPosition(){return position;}

    Rectangle GetCollider(){return boxCollider;};
    void DrawDebug();
    EnemyType GetEnemyType() {return type;}



protected:
    void GenerateRandomSpawnPositions();
    EnemyType type;

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