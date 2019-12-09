#pragma once
#include "GameStateHandler.h"
class GameLoader {
public:
	static void loadScene(GamePlayState state);

private:
	static void loadTitleScreen();
	static void loadOverworld();
	static void unloadAndFreePreviousScene();
};