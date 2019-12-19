#pragma once
#include "../../Logic/Logic.h"
#include "../../Graph/Overworld/OverworldGraph.h"


class OverWorldLogic : public Logic {
public:


	OverWorldLogic(Graph* g) : Logic(g) {};

	void handleEvent(const Uint8* keys);
	void free();
	bool checkIfPlayerColliding(MTT_GraphicalObject* object);
	void checkIfPlayerInLoadingArea();
	SDL_Rect loadingArea{ 0,0,50,50 };
	Player* player = NULL;

	

private:
	bool checkCollisionsBetweenTwoRectangles(SDL_Rect rect1, SDL_Rect rect2);
	void cancelLastMove();

	int lastXCoorOfPlayer = 0;
	int lastYCoorOfPlayer = 0;


};