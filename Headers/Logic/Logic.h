#pragma once
#include "../Graph/Graph.h"

class Logic
{

public:
	Logic(Graph* g);
	virtual void handleHighPrecisionEvent(const Uint8* keys) = 0;
	virtual void handleLowPrecisionEvent(SDL_Event e);
	virtual void free() = 0;

protected:
	Graph* graph;
};