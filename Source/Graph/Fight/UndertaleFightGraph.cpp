#include "../../../Headers/Graph/Fight/UndertaleFightGraph.h"

void UndertaleFightGraph::update()
{
	SDL_RenderClear(Graphics::graphicHandler.gameRenderer);

	//No need to render the player in undertale mode!
	//However, we will need to render the menu,
	//the dialogue box,
	//the enemies,
	//And the pellets. Phew.

	//First, let's just try to render the dialogueBox and mettaton.
	SDL_RenderDrawRect(this->renderer, &this->dialogueBox);
	enemy->GAO->render(this->camera);

}

void UndertaleFightGraph::load()
{
	//nothing to load.
}

void UndertaleFightGraph::free()
{
	delete this->enemy;
}


