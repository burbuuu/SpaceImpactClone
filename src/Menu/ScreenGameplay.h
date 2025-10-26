#pragma once
#include <raylib.h>

#include "StateMachineMngr.h"
#include "Game/Player.h"
#include "Game/GlobalGameDefines.h"
#include "Game/Enemies/BaseEnemy.h"
#include "Game/Enemies/Boss.h"
#include "Game/Managers/BulletManager.h"
#include "Game/Managers/EnemyManager.h"
#include "Game/UI/HealthContainer.h"

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

	int framesCounter = 0;
	int finishScreen = 0;

	//Background Textures
	Texture2D landscapeText;

	//Sounds
	Sound fxStart;

	//UI
	HealthContainer healthContainer{};

	//Player, enemy manager and bullet manager
	BulletManager bulletManager{};
	EnemyManager enemyManager{};
	Player player;




	//Enemy methods
	void HandleCollisions(void);
	void CheckForDeadEnemies();

	//Boss
	bool isBossSpawn = false;
	bool isBossDefeated;
	float bossSpawnTimer;
	float const BOSS_SPAWN_DELAY = 20.0f;
	void CheckForBossSpawns(float deltaTime);
};
