#pragma once
#include <SDL.h>
#include "Graph/Graph.h"
class GraphicHandler {

public:
	static SDL_Window* gameWindow;
	static SDL_Renderer* gameRenderer;

	static void setCurrentGraph(Graph* newGraph);
	static void update();

private:

	static Graph* currentGraph;
};