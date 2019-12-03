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

	int x = 200; //Temp
	int y = 200; //temp

	void update();

	void load();

	Player* player;


private:

	MTT_Texture backGroundTexture;


};