#include "../Headers/GraphicHandler.h"



void GraphicHandler::setCurrentGraph(Graph* newGraph)
{
	GraphicHandler::currentGraph = newGraph;
}

void GraphicHandler::update()
{
	GraphicHandler::currentGraph->update();
}

void GraphicHandler::free()
{
	this->currentGraph->free();
}


GraphicHandler Graphics::graphicHandler;




