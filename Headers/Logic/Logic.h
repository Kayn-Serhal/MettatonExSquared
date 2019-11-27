#pragma once
#include "../Graph/Graph.h"

class Logic
{

public:
	Logic(Graph* g);
	virtual void handleEvent(SDL_Event e) = 0;

protected:
	Graph* graph;
};