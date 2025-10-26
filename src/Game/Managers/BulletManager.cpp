//
// Created by iris on 15/10/2025.
//

#include "BulletManager.h"

#include <algorithm>

BulletManager::BulletManager() {
}

void BulletManager::UpdateBullets(float deltaTime) {
    for (auto& bullet : bullets) {
        bullet.Update(deltaTime);
    }

    bullets.erase(
        std::remove_if(
            bullets.begin(),
            bullets.end(),
            [](const Bullet &bullet) {
                return bullet.GetPosition().x > GameGlobalVar::gameplayRightBorder+100;
            }
        ),
        bullets.end()
    );
}

void BulletManager::DrawBullets() {
    for (auto& bullet : bullets) {
        bullet.Draw();
    }

}

void BulletManager::ShootBullet(Vector2 position, bool isPlayerBullet) {
    bullets.emplace_back(position, isPlayerBullet);
}

void BulletManager::ShootBullet(Vector2 position) {
    bullets.emplace_back(position);
}

void BulletManager::RemoveBullet(Bullet& bullet) {
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
            [&](const Bullet& b) { return &b == &bullet; }),
        bullets.end()
    );
}
