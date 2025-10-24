
#pragma once

#include "ScreenGameplay.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/GlobalGameDefines.h"
#include  "Game/Player.h"

#include <string>


ScreenGameplayState::ScreenGameplayState() : player(playerStartPosition,bulletManager){
}

ScreenGameplayState& ScreenGameplayState::getInstance()
{
	static ScreenGameplayState singleton;
	return singleton;
}

void ScreenGameplayState::InitScreen(void)
{
	framesCounter = 0;
	finishScreen = 0;

	//Load textures
	landscapeText = LoadTexture("resources/Game/Landscape.png");
}

void ScreenGameplayState::UpdateScreen(float deltaTime)
{
	EvaluateInput();

	//put here all the code for updating in the screen the gameplay

	player.Update(deltaTime); // Player input evaluates inside player class
	bulletManager.UpdateBullets(deltaTime);
	enemyManager.Update(deltaTime);

	HandleCollisions();
	CheckForDeadEnemies();
}

void ScreenGameplayState::DrawScreen(void)
{

	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

	//put here all the code for drawing in the screen the gameplay
	DrawTexture(landscapeText,
		GameGlobalVar::screenWidth/2 - landscapeText.width/2,
		GameGlobalVar::screenHeight/2 - landscapeText.height/2,
		WHITE);
	player.Draw();
	bulletManager.DrawBullets();
	enemyManager.DrawEnemies();

	//Draw debug
	if (IsKeyDown(KEY_B)) {
		player.DrawDebug();
		enemyManager.DrawDebug();
	}


	// TODO: UI Score, lives

	Font font = GameInst.GetFont();

	DrawText("SCORE:", 300.f, 100.f, 25, WHITE);
	DrawText(to_string(GameInst.GetScore()).c_str(), 440.f, 100.f, 25, WHITE);
}

void ScreenGameplayState::UnloadScreen(void)
{
	UnloadTexture(landscapeText);
}

int  ScreenGameplayState::FinishScreen(void)
{
	if (player.GetHealth() <= 0) {
		finishScreen = 4;
	}
	return finishScreen;
}

void ScreenGameplayState::EvaluateInput()
{
	//DEBUG take damage buttor
	if (IsKeyPressed(KEY_F)){

	}

	// DEBUG Delete or modify this when the project is more advanced
	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 4;   // END SCREEN
	}
}

	void ScreenGameplayState::DebugOptions()
{

}

void ScreenGameplayState::DrawDebug()
{
	GameManager& GameInst = GameManager::GetGameManager();

}

void ScreenGameplayState::HandleCollisions() {
	auto& bullets = bulletManager.GetBullets();
	auto& enemies = enemyManager.GetEnemies();
	Rectangle playerCollider = player.GetCollider();

	//Check player vs enemies
	for (auto* enemy : enemies) {
		if (CheckCollisionRecs(playerCollider, enemy->GetCollider())) {
			TraceLog(LOG_INFO, "Player collided with enemy!");
			player.TakeDamage(1);
			enemyManager.DestroyEnemy(enemy);
		}
	}
	//Bullet vs enemies
	for (auto* enemy : enemies) {
		for (auto bullet : bullets) {
			if (CheckCollisionRecs(bullet.GetCollider(), enemy->GetCollider())) {
				enemy->TakeDamage(1);
				bulletManager.RemoveBullet(bullet);
			}
		}
	}
}

void ScreenGameplayState::CheckForDeadEnemies() {
	std::vector<BaseEnemy*> enemies = enemyManager.GetEnemies();
	std::vector<BaseEnemy*> toDestroy;

	//Get dead enemies on a vector for destroying them
	for (auto* enemy : enemies) {
		if (enemy->GetHealth() <= 0) {
			GameManager::GetGameManager().IncreaseScore(enemy->GetScore());
			toDestroy.push_back(enemy);
		}
	}

	for (auto* enemy : toDestroy) {
		enemyManager.DestroyEnemy(enemy);
	}
}
