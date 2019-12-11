#pragma once
#include "../Graph.h"
#include "../../CoreComponents/MTT_Texture.h"
#include "../../GameComponents/Player/Player.h"
#include "../../GameComponents/Cat.h"

class OverworldGraph : public Graph
{
public:
	OverworldGraph(SDL_Renderer* r) : Graph(r) {
		this->load();
	}

	const int LEVELWIDTH = 1000;
	const int LEVELHEIGHT = 1000;

	void update();

	void load();

	void free();

	

	Player* player;
	Cat* aRandomCat = 0;

	

	


private:

	void checkIfPlayerIsTryingToGoOutOfBoundsBecauseHeIsProllyADumbass();
	void checkIfCameraIsTryingToGoOutOfBounds();
	MTT_Texture backGroundTexture;


};