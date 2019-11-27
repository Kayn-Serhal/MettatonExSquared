#include "../Headers/GameLoader.h"
#include "../Headers/Scenes/TitleScreen/TitleScreenScene.h"
#include "../Headers/Graph/TitleScreen/TitleScreenGraph.h"
#include "../Headers/Logic/TitleScreen/TitleScreenLogic.h"
#include "../Headers/GraphicHandler.h"
#include "../Headers/Components/MetTexture.h"
#include "../Headers/Graph/Graph.h"
#include "../Headers/Scenes/Scene.h"
#include "../Headers/InputHandler.h"

void GameLoader::loadScene(GamePlayState state)
{

	TitleScreenGraph* titleScreenGraphicalManager = new TitleScreenGraph(GraphicHandler::gameRenderer);
	TitleScreenLogic* titleScreenLogicalManager = new TitleScreenLogic(titleScreenGraphicalManager);
	//Temporary, just for testing purposes
	InputHandler::setCurrentLogic(titleScreenLogicalManager);
	GraphicHandler::setCurrentGraph(titleScreenGraphicalManager);

	TitleScreenScene* sceneToDisplay = new TitleScreenScene(titleScreenGraphicalManager, titleScreenLogicalManager);
	sceneToDisplay->display();

}
