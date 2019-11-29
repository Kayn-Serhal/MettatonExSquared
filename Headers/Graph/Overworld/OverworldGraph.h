#pragma once
#include "../Graph.h"
#include "../../Components/MetTexture.h"
#include "../../Components/Player.h"

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

	MetTexture backGroundTexture;
	MetTexture spriteTexture;


};