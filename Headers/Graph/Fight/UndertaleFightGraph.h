#pragma once
#include "../Graph.h"
#include "../../CoreComponents/MTT_Texture.h"
#include "../../GameComponents/Player/Player.h"
#include <string>


class UndertaleFightGraph : public Graph
{

public:

	UndertaleFightGraph(SDL_Renderer* r) : Graph(r) {
		this->load();
	}






};