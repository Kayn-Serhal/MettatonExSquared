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
	TitleScreenGraph* titleScreenGraphicalManager = new TitleScreenGraph(Graphics::graphicHandler.gameRenderer);
	TitleScreenLogic* titleScreenLogicalManager = new TitleScreenLogic(titleScreenGraphicalManager);
	Inputs::inputHandler.setCurrentLogic(titleScreenLogicalManager);
	Graphics::graphicHandler.setCurrentGraph(titleScreenGraphicalManager);

	TitleScreenScene* sceneToDisplay = new TitleScreenScene(titleScreenGraphicalManager, titleScreenLogicalManager);
	GameLoader::currentScene = sceneToDisplay;
	//No need to bother with a scene here

}

void GameLoader::loadOverworld()
{

	OverworldGraph* overworldGraphicalManager = new OverworldGraph(Graphics::graphicHandler.gameRenderer);
	OverWorldLogic* overworldLogicManager = new OverWorldLogic(overworldGraphicalManager);

	Inputs::inputHandler.setCurrentLogic(overworldLogicManager);
	Graphics::graphicHandler.setCurrentGraph(overworldGraphicalManager);

	OverWorldScene* sceneToDisplay = new OverWorldScene(overworldGraphicalManager, overworldLogicManager);
	GameLoader::currentScene = sceneToDisplay;
}


//This is pretty important and will be used in order to prevent memory leaks so be careful with that
void GameLoader::unloadAndFreePreviousScene()
{
	GameLoader::currentScene->free();
	delete GameLoader::currentScene;
}

Scene* GameLoader::currentScene;




