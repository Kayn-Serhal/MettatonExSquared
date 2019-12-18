#pragma once
#include "../Graph.h"
#include "../../CoreComponents/MTT_Texture.h"
#include "../../GameComponents/Player/Player.h"
#include "../../GameComponents/Enemy/UndertaleMode/UndertaleEnemy.h"
#include <string>


class UndertaleFightGraph : public Graph
{

public:

	UndertaleFightGraph(SDL_Renderer* r) : Graph(r) {
		this->load();
	}

	void update();

	void load();

	void free();

	UndertaleEnemy* enemy = 0;

	Player* player = 0;

	SDL_Rect dialogueBox;
};