#pragma once
#include "../Graph/Graph.h"

class Logic
{

public:
	Logic(Graph* g);
	virtual void handleEvent(SDL_Event e) = 0;
	virtual void handleEvent(const Uint8* keys) = 0;

protected:
	Graph* graph;
};