#pragma once
#include "../Scene.h"
#include "../../GameComponents/Player/Player.h"
#include "../../GameComponents/Enemy/UndertaleMode/UndertaleEnemy.h"

class UndertaleFightScene : public Scene
{
public :
	UndertaleFightScene(Graph* g, Logic* l) : Scene(g, l) {
	}

	void update();
	void free();

	
	Player* player = 0;

	UndertaleEnemy* enemy = 0;

};