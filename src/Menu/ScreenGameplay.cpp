
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

	//Load player and enemy manager

}

void ScreenGameplayState::UpdateScreen(float deltaTime)
{
	EvaluateInput();

	//put here all the code for updating in the screen the gameplay

	player.Update(deltaTime); // Player input evaluates inside player class
	bulletManager.UpdateBullets(deltaTime);

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
	//DEBUG take damage
	if (IsKeyPressed(KEY_F)){player.TakeDamage(1);}

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