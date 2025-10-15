#include "ScreenTitle.h"
#include "raylib.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/GameManager.h"

ScreenTitleState& ScreenTitleState::getInstance()
{
	static ScreenTitleState singleton;
	return singleton;
}


void ScreenTitleState::InitScreen(void)
{
	framesCounter = 0;
	finishScreen = 0;
	TraceLog(LOG_INFO, "ScreenTitleState::InitScreen");

	// Use this to access to the Game instance
	GameManager& GameInst = GameManager::GetGameManager();

	//Load title texture
	textTitle = LoadTexture("resources/Menu/MainLogo.png");
}

void ScreenTitleState::UpdateScreen(float deltaTime)
{
	GameManager& GameInst = GameManager::GetGameManager();


	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		finishScreen = 2;   // GAMEPLAY
	}

	if (IsKeyPressed(KEY_O))
	{
		finishScreen = 1;   // OPTIONS
	}
}

void ScreenTitleState::DrawScreen(void)
{
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

	GameManager& GameInst = GameManager::GetGameManager();

	float posx = ((GetScreenWidth() / 2.f) - (MeasureText("by Iris G. G.", 20) / 2.f));

	DrawTextEx(GameInst.GetFont(), " by Iris G. G.", Vector2{ posx, 450.f }, 20, 4, WHITE);

	DrawText("Press Enter for Playing", (GetScreenWidth() / 2) - (MeasureText("Press Enter for Playing", 25) / 2), 500, 25, WHITE);
	DrawText("Press 'O' for Instructions", (GetScreenWidth() / 2) - (MeasureText("Press 'O' for Instructions", 25) / 2), 560, 25, WHITE);

	//Draw the title screen
	//TODO animation
	DrawTexture(
		textTitle,
		GameGlobalVar::screenWidth/2 - textTitle.width/2,
		    - GameGlobalVar::screenHeight/8 + textTitle.height/2,
		WHITE);

}

void ScreenTitleState::UnloadScreen(void)
{
	GameManager& GameInst = GameManager::GetGameManager();
	UnloadTexture(textTitle);
}

int ScreenTitleState::FinishScreen(void)
{
	return finishScreen;
}