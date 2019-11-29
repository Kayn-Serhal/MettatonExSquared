#pragma once
#include "../../Logic/Logic.h"
#include "../../Graph/Overworld/OverworldGraph.h"
class OverWorldLogic : public Logic {
public:
	OverWorldLogic(Graph* g) : Logic(g) {};

	void handleEvent(SDL_Event e);
	void handleEvent(const Uint8* keys);
	Player* player = NULL;
};