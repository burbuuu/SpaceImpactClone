#pragma once
#include <raylib.h>

#include "StateMachineMngr.h"
#include "Game/Player.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Managers/BulletManager.h"
#include "Game/Managers/EnemyManager.h"

class ScreenGameplayState : public StateMachineMngr
{
public:

	void enter(Screen* screen) {}
	void toggle(Screen* screen) {};
	void exit(Screen* screen) {};

	virtual void InitScreen(void);
	virtual void UpdateScreen(float deltaTime);
	virtual void DrawScreen(void);
	virtual void UnloadScreen(void);
	virtual int FinishScreen(void);

	int getScreenId() { return (int)ScreenState::GAMEPLAY; }

	static ScreenGameplayState& getInstance();

private:
	ScreenGameplayState();
	ScreenGameplayState(const ScreenGameplayState& other);
	ScreenGameplayState& operator = (const ScreenGameplayState& other);

	void EvaluateInput();
	
	void DebugOptions();
	void DrawDebug();

	int framesCounter = 0;
	int finishScreen = 0;
	bool mb_ReplayLevel = false;

	bool debug_floor = false;
	bool debug_stairs = false;

	//Background Textures
	Texture2D landscapeText;

	//Player, enemy manager and bullet manager
	BulletManager bulletManager{};
	EnemyManager enemyManager{};
	const Vector2 playerStartPosition {0,GameGlobalVar::screenHeight/2};
	Player player;

	void HandleCollisions(void);

	void CheckForDeadEnemies();
};
