#pragma once
#include "GameStateHandler.h"
#include "../Headers/Scenes/Scene.h"
#include <string>

class GameLoader {
public:
	static void loadScene(GamePlayState state);
	static void loadOverworldScene(std::string area, std::string subArea);


private:
	static void loadTitleScreen();
	static void loadOverworld();
	static void loadOverworld(std::string area, std::string subArea);
	static void unloadAndFreePreviousScene();
	static Scene* currentScene;
	static bool boolCat;
};