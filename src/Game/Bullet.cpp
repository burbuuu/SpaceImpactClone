//
// Created by iris on 15/10/2025.
//

#include "Bullet.h"
#include <raylib.h>
#include "GlobalGameDefines.h"

//More general constructor, used for player or enemy bullets
Bullet::Bullet(Vector2 pos, bool isMovingForward){
	position = pos;
	if (isMovingForward) {
		speed = BULLET_SPEED;
	}
	else {
		speed = -BULLET_SPEED;
	}
}

// Simpler constructor, used for player bullets only
Bullet::Bullet(Vector2 pos ){
	position = pos;
	speed = BULLET_SPEED;
}

void Bullet::Update(float deltaTime){
	position.x += speed * deltaTime;

}

void Bullet::Draw(){
	DrawRectangleV(position, size, GREENLIGHT);
}