#pragma once
#include <SDL.h>
#include "Graph/Graph.h"


class GraphicHandler {

public:
	SDL_Window* gameWindow = NULL;
	SDL_Renderer* gameRenderer = NULL;

	void setCurrentGraph(Graph* newGraph);
	void update();
	void free();

private:

	Graph* currentGraph = NULL;
};

namespace Graphics {

	extern GraphicHandler graphicHandler;
}