#include "../Headers/GraphicHandler.h"


SDL_Window* GraphicHandler::gameWindow = NULL;
SDL_Renderer* GraphicHandler::gameRenderer = NULL;

void GraphicHandler::setCurrentGraph(Graph* newGraph)
{
	GraphicHandler::currentGraph = newGraph;
}

void GraphicHandler::update()
{
	GraphicHandler::currentGraph->update();
}

Graph* GraphicHandler::currentGraph = 0;



