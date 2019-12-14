#pragma once
#include "GameStateHandler.h"
#include "../Headers/Scenes/Scene.h"
#include <string>
#include "GameComponents/Player/Player.h"

class GameLoader {
public:
	static void loadScene(GamePlayState state);
	static void loadOverworldScene(std::string area, std::string subArea);
	static void loadOverworldScene(std::string area, std::string subArea, Player* player);

private:
	static void loadTitleScreen();
	static void loadOverworld();
	static void loadOverworld(std::string area, std::string subArea);
	static void loadOverworld(std::string area, std::string subArea, Player* player);
	static void unloadAndFreePreviousScene();
	static Scene* currentScene;
	static bool boolCat;
};