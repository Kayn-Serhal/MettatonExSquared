#include "../Headers/GraphicHandler.h"



void GraphicHandler::setCurrentGraph(Graph* newGraph)
{
	GraphicHandler::currentGraph = newGraph;
}

void GraphicHandler::update()
{
	GraphicHandler::currentGraph->update();
}

GraphicHandler Graphics::graphicHandler;




