#pragma once
#include "../Scene.h"
#include "../../Graph/Overworld/OverworldGraph.h"
#include "../../Logic/Overworld/OverWorldLogic.h"
#include <vector>
class OverWorldScene : public Scene
{
public:
	OverWorldScene(Graph* g, Logic* l) : Scene(g, l) {
		this->player = new Player();
		((OverworldGraph*)this->graphical)->player = this->player;
		((OverWorldLogic*) this->logical)->player = this->player;
	};

	OverWorldScene(Graph* g, Logic* l, bool cat): Scene(g,l) {
		this->player = new Player();
		((OverworldGraph*)this->graphical)->player = this->player;
		((OverWorldLogic*)this->logical)->player = this->player;
	};

	OverWorldScene(Graph* g, Logic* l, Player* player) : Scene(g, l) {
		this->player = player;
		((OverworldGraph*)this->graphical)->player = this->player;
		((OverWorldLogic*)this->logical)->player = this->player;
	};

	void update();

	void free();

	Player* player;


};