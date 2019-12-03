#pragma once
#include "../Graph.h"
#include "../../Components/MTT_Texture.h"

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

	MTT_Texture titleScreenTexture;

};