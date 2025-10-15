//
// Created by iris on 15/10/2025.
//

#ifndef SPACEIMPACT_BULLET_H
#define SPACEIMPACT_BULLET_H
#include <raylib.h>


class Bullet {
public:
    Bullet(Vector2 pos);
    ~Bullet();

    void Update();
    void Draw();

private:
    Vector2 position;
    const Vector2 size;
    const Vector2 initialPositionOffset;
    const Vector2 speed;
};

#endif //SPACEIMPACT_BULLET_H