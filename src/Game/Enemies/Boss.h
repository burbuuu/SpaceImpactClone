//
// Created by iris on 24/10/2025.
//

#ifndef SPACEIMPACT_BOSS_H
#define SPACEIMPACT_BOSS_H
#include "BaseEnemy.h"
#include "Game/Managers/BulletManager.h"
#include "raymath.h"
#include "raylib.h"


class Boss : public BaseEnemy{
public:
    Boss(BulletManager &bullet_manager);
    void EnemyInit() override;
    void Update(float deltaTime) override;



private:
    BulletManager &bulletManager;
    void Shoot();
    void CheckForShoot(float deltaTime);
    float shootTimer;
    float const SHOOT_TIME = 1.5f;
    float const INITIAL_POS_Y = GameGlobalVar::screenHeight/2 - 115;

    int const FINAL_POSITION = GameGlobalVar::gameplayRightBorder - 200;
    Vector2 const SHOOT_OFFSET = Vector2 {-10,115};
};


#endif //SPACEIMPACT_BOSS_H