#pragma once
#include "../Graph.h"
#include "../../Components/MetTexture.h"

class TitleScreenGraph : public Graph
{
public:
	TitleScreenGraph(SDL_Renderer* r) :Graph(r) {
		this->load();
	}

	void fuckShitUp();

	void load();

	void update();



private:

	MetTexture titleScreenTexture;

};