#include "../Headers/GameLoader.h"
#include "../Headers/Scenes/TitleScreen/TitleScreenScene.h"
#include "../Headers/Graph/TitleScreen/TitleScreenGraph.h"
#include "../Headers/Logic/TitleScreen/TitleScreenLogic.h"
#include "../Headers/GraphicHandler.h"
#include "../Headers/Graph/Graph.h"
#include "../Headers/InputHandler.h"
#include "../Headers/Scenes/Overworld/OverWorldScene..h"
#include "../Headers/Logic/Overworld/OverWorldLogic.h"
#include "../Headers/Graph/Overworld/OverworldGraph.h"



void GameLoader::loadScene(GamePlayState state)
{
	
	if(GameLoader::currentScene !=NULL)
		unloadAndFreePreviousScene();

	switch (state)
	{
	case GamePlayState::FIGHT:break; //not implemented yet
	case GamePlayState::LOADING: break; //Same
	case GamePlayState::MOCKTITLE: loadTitleScreen(); break;
	case GamePlayState::OVERWORLD: loadOverworld(); break;
	}
}

void GameLoader::loadTitleScreen()
{
	GameStateHandler::currentGamePlayState = GamePlayState::LOADING;
	TitleScreenGraph* titleScreenGraphicalManager = new TitleScreenGraph(Graphics::graphicHandler.gameRenderer);
	TitleScreenLogic* titleScreenLogicalManager = new TitleScreenLogic(titleScreenGraphicalManager);
	Inputs::inputHandler.setCurrentLogic(titleScreenLogicalManager);
	Graphics::graphicHandler.setCurrentGraph(titleScreenGraphicalManager);

	TitleScreenScene* sceneToDisplay = new TitleScreenScene(titleScreenGraphicalManager, titleScreenLogicalManager);
	GameLoader::currentScene = sceneToDisplay;
	GameStateHandler::currentGamePlayState = GamePlayState::MOCKTITLE;

}

void GameLoader::loadOverworld()
{
	GameStateHandler::currentGamePlayState = GamePlayState::LOADING;
	OverworldGraph* overworldGraphicalManager = new OverworldGraph(Graphics::graphicHandler.gameRenderer);
	OverWorldLogic* overworldLogicManager = new OverWorldLogic(overworldGraphicalManager);

	Inputs::inputHandler.setCurrentLogic(overworldLogicManager);
	Graphics::graphicHandler.setCurrentGraph(overworldGraphicalManager);

	OverWorldScene* sceneToDisplay = new OverWorldScene(overworldGraphicalManager, overworldLogicManager);
	GameLoader::currentScene = sceneToDisplay;

	Cat* cat = new Cat(350,350);
	cat->loadSpriteFromFilename("Cat.png");
	if(boolCat)
	overworldGraphicalManager->aRandomCat = cat;
	GameLoader::boolCat = !boolCat;

	GameStateHandler::currentGamePlayState = GamePlayState::OVERWORLD;
}


//This is pretty important and will be used in order to prevent memory leaks so be careful with that
void GameLoader::unloadAndFreePreviousScene()
{
	Inputs::inputHandler.setCurrentLogic(NULL);
	Graphics::graphicHandler.setCurrentGraph(NULL);
	delete GameLoader::currentScene;
	GameLoader::currentScene = NULL;
}

Scene* GameLoader::currentScene;
bool GameLoader::boolCat = false;