//
// Created by iris on 15/10/2025.
//

#ifndef SPACEIMPACT_BULLET_H
#define SPACEIMPACT_BULLET_H
#include <raylib.h>
#include "GlobalGameDefines.h"


class Bullet {
public:
	Bullet(Vector2 pos);
    Bullet(Vector2 pos, bool isMovingForward );

    void Update(float deltaTime);
    void Draw();

private:
    Vector2 position;
    const Vector2 size = Vector2{ 10, 5 };
	float speed;
	const float BULLET_SPEED = 500.0f;

};

#endif //SPACEIMPACT_BULLET_H