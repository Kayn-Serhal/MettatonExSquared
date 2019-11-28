#include "../../../Headers/Logic/Overworld/OverWorldLogic.h"
#include "../../../Headers/Graph/Overworld/OverworldGraph.h"

void OverWorldLogic::handleEvent(SDL_Event e) 
{
	if (e.type == SDL_KEYDOWN)
	{
		printf("EVENT");
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			((OverworldGraph*)this->graph)->y--;
			break;

		case SDLK_DOWN:
			((OverworldGraph*)this->graph)->y--;
			break;

		case SDLK_LEFT:
			((OverworldGraph*)this->graph)->x--;
			break;

		case SDLK_RIGHT:
			((OverworldGraph*)this->graph)->x++;
			break;
		}
	}
}