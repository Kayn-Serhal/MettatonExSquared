#pragma once
#include "GameStateHandler.h"
#include "../Headers/Scenes/Scene.h"
class GameLoader {
public:
	static void loadScene(GamePlayState state);


private:
	static void loadTitleScreen();
	static void loadOverworld();
	static void unloadAndFreePreviousScene();
	static Scene* currentScene;
	static bool boolCat;
};