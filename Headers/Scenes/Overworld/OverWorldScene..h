#pragma once
#include "../Scene.h"
class OverWorldScene : public Scene
{
public:
	OverWorldScene(Graph* g, Logic* l) : Scene(g, l) {};

	void update();

};