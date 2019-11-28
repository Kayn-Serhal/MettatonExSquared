#pragma once
#include "../Scene.h"
class TitleScreenScene : public Scene
{
public : 
	TitleScreenScene(Graph* g, Logic* l):Scene(g, l) {};

	void update();

};