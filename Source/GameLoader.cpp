#include "../Headers/GameLoader.h"
#include "../Headers/Scenes/TitleScreen/TitleScreenScene.h"
#include "../Headers/Graph/TitleScreen/TitleScreenGraph.h"
#include "../Headers/Logic/TitleScreen/TitleScreenLogic.h"
#include "../Headers/GraphicHandler.h"
#include "../Headers/Components/MetTexture.h"
#include "../Headers/Graph/Graph.h"
#include "../Headers/Scenes/Scene.h"

void GameLoader::loadScene(GamePlayState state)
{

			TitleScreenScene* sceneToDisplay = new TitleScreenScene(new TitleScreenGraph(GraphicHandler::gameRenderer), new TitleScreenLogic());
			sceneToDisplay->display();

}
