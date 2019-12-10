#pragma once
#include "../../Logic/Logic.h"
#include "../../Graph/TitleScreen/TitleScreenGraph.h"
class TitleScreenLogic : public Logic{

public:
	TitleScreenLogic(Graph* g) : Logic(g) {};

	void handleEvent(const Uint8* keys);

	void free();

};