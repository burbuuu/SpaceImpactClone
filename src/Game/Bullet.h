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
    Bullet(Vector2 pos, bool isPlayerBullet );

    void Update(float deltaTime);
    void Draw();
	inline Vector2 GetPosition() const {return position;}
	Rectangle GetCollider() const{return Rectangle{position.x,position.y,size.x,size.y};};

private:
    Vector2 position;
    static constexpr Vector2 size = Vector2{ 10, 5 };
	float speed;
	static constexpr float BULLET_SPEED = 450.0f;

};

#endif //SPACEIMPACT_BULLET_H