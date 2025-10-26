
#pragma once

#include "ScreenGameplay.h"
#include "raylib.h"
#include "Game/Managers/GameManager.h"
#include "Game/GlobalGameDefines.h"
#include  "Game/Player.h"

#include <string>


ScreenGameplayState::ScreenGameplayState() : player(bulletManager){
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

	//Load textures and sounds
	landscapeText = LoadTexture("resources/Game/Landscape.png");
	fxStart = LoadSound("resources/Sounds/StartGame.mp3");
	PlaySound(fxStart);

	//UI
	healthContainer.Init();

	//Reset player anb managers
	player.InitPlayer();
	enemyManager.Init();

	//Reset boss spawn timer
	bossSpawnTimer = 30.0f;
	isBossSpawn = false;
	isBossDefeated = false;

}

void ScreenGameplayState::UpdateScreen(float deltaTime)
{
	EvaluateInput();


	player.Update(deltaTime); // Player input evaluates inside player class
	bulletManager.UpdateBullets(deltaTime);
	enemyManager.Update(deltaTime);
	CheckForBossSpawns(deltaTime);

	HandleCollisions();
	CheckForDeadEnemies();
}

void ScreenGameplayState::DrawScreen(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

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


	// UI Score and lives

	Font font = GameInst.GetFont();

	DrawText("SCORE:", 600.f, 100.f, 25, WHITE);
	DrawText(to_string(GameInst.GetScore()).c_str(), 740.f, 100.f, 25, WHITE);

	// Draw players lives
	healthContainer.Draw(player.GetHealth());
}

void ScreenGameplayState::UnloadScreen(void)
{
	UnloadTexture(landscapeText);
	UnloadSound(fxStart);
	healthContainer.Unload();
	enemyManager.ClearEnemies(); // This destroys unloads their resources and then destroys all enemies
	player.UnloadResources();
}

int  ScreenGameplayState::FinishScreen(void)
{
	// Player dead
	if (player.GetHealth() <= 0) {
		finishScreen = (int)ScreenState::ENDING;
	}

	// Boss defeated
	if (isBossDefeated) {
		finishScreen = (int)ScreenState::ENDING;
	}

	return finishScreen;
}

void ScreenGameplayState::EvaluateInput()
{

	// DEBUG Delete or modify this when the project is more advanced
	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 4;   // END SCREEN
	}
}

void ScreenGameplayState::HandleCollisions() {
	auto& bullets = bulletManager.GetBullets();
	auto& enemies = enemyManager.GetEnemies();
	Rectangle playerCollider = player.GetCollider();

	//Check player vs enemies
	for (auto* enemy : enemies) {
		if (CheckCollisionRecs(playerCollider, enemy->GetCollider())) {

			//If player is not invulnerable take damage
			if (!player.IsPlayerInvulnerable()) {
				player.TakeDamage(1);

				//Destroy enemy if it's a regular enemy, but this is not intended for the boss
				if (enemy->GetEnemyType() == EnemyType::REGULAR) {
					enemyManager.DestroyEnemy(enemy);
				}
			}
		}
	}

	//Bullet vs enemies
	for (auto* enemy : enemies) {
		for (auto it = bullets.begin(); it != bullets.end(); ) {
			if (CheckCollisionRecs(it->GetCollider(), enemy->GetCollider())) {
				enemy->TakeDamage(1);
				//Remove the bullet if the enemy is hit
				it = bullets.erase(it);
			} else {
				++it;
			}
		}
	}

	// Bullet vs player
	for (auto it = bullets.begin(); it != bullets.end();) {
		if (CheckCollisionRecs(it->GetCollider(), playerCollider)) {
			player.TakeDamage(1);
			//Remove bullet if the player is hit
			it = bullets.erase(it);
		} else {
			++it;
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

			//Check if the defeated enemy is the boss
			if (enemy->GetEnemyType() == EnemyType::BOSS) {
				isBossDefeated = true;
			}
			toDestroy.push_back(enemy);
		}
	}

	for (auto* enemy : toDestroy) {
		enemyManager.DestroyEnemy(enemy);
	}
}

void ScreenGameplayState::CheckForBossSpawns(float deltaTime) {
		// Update boss timer
		bossSpawnTimer -= deltaTime;

		if (bossSpawnTimer <= 0.0f && !isBossSpawn) {
			isBossSpawn = true;
			enemyManager.SpawnBoss(bulletManager);
		}

}
