//
// Created by iris on 15/10/2025.
//

#include "Bullet.h"
#include <raylib.h>
#include "GlobalGameDefines.h"

//More general constructor, used for player or enemy bullets
Bullet::Bullet(Vector2 pos, bool isPlayerBullet){
	position = pos;
	if (isPlayerBullet) {
		speed = BULLET_SPEED;
	}
	else {
		speed = -BULLET_SPEED; // Enemy bullet goes backwards
	}
}

// Simpler constructor, used for player bullets only
Bullet::Bullet(Vector2 pos){
	position = pos;
	speed = BULLET_SPEED;
}

void Bullet::Update(float deltaTime){
	position.x += speed * deltaTime;
}

void Bullet::Draw(){
	//TODO: If it is an enemy bullet choose another color
	DrawRectangleV(position, size, GREENLIGHT);
}