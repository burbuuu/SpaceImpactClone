//
// Created by iris on 15/10/2025.
//

#ifndef SPACEIMPACT_BULLETMANAGER_H
#define SPACEIMPACT_BULLETMANAGER_H

#include <raylib.h>
#include <vector>
#include "../Bullet.h"


class BulletManager {
    public:
    BulletManager();

    void UpdateBullets(float deltaTime);
    void DrawBullets();
    void ShootBullet(Vector2 position, bool isPlayerBullet);
    void ShootBullet(Vector2 position);
    const std::vector<Bullet>& GetBullets() const { return bullets; }
    void RemoveBullet(const Bullet& bullet);

    private:
    std::vector<Bullet> bullets;

};


#endif //SPACEIMPACT_BULLETMANAGER_H