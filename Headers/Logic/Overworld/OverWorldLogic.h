#pragma once
#include "../../Logic/Logic.h"
#include "../../Graph/Overworld/OverworldGraph.h"
class OverWorldLogic : public Logic {
public:
	OverWorldLogic(Graph* g) : Logic(g) {};

	void handleEvent(SDL_Event e);

	Player* player;
};