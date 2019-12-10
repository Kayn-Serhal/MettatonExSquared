#pragma once
#include "../Graph.h"
#include "../../CoreComponents/MTT_Texture.h"

class TitleScreenGraph : public Graph
{
public:
	TitleScreenGraph(SDL_Renderer* r) :Graph(r) {
		this->load();
	}

	void load();

	void update();

	void free();



private:

	MTT_Texture titleScreenTexture;

};