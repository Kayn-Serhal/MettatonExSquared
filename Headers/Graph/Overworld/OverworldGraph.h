#pragma once
#include "../Graph.h"
#include "../../CoreComponents/MTT_Texture.h"
#include "../../GameComponents/Player/Player.h"

class OverworldGraph : public Graph
{
public:
	OverworldGraph(SDL_Renderer* r) : Graph(r) {
		this->load();
	}

	const int LEVELWIDTH = 2000;
	const int LEVELHEIGHT = 1500;

	void update();

	void load();

	void free();

	

	Player* player;


private:

	void checkIfPlayerIsTryingToGoOutOfBoundsBecauseHeIsProllyADumbass();
	void checkIfCameraIsTryingToGoOutOfBounds();
	MTT_Texture backGroundTexture;


};