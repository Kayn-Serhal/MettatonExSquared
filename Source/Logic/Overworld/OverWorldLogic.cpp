#include "../../../Headers/Logic/Overworld/OverWorldLogic.h"
#include "../../../Headers/Graph/Overworld/OverworldGraph.h"

void OverWorldLogic::handleEvent(SDL_Event e) 
{

	const Uint8* key = SDL_GetKeyboardState(NULL);
	if (key[SDL_SCANCODE_RIGHT])
	{
		/*switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			((OverworldGraph*)this->graph)->y= ((OverworldGraph*)this->graph)->y -Player::VELOCITY;
			break;

		case SDLK_DOWN:
			((OverworldGraph*)this->graph)->y = ((OverworldGraph*)this->graph)->y + Player::VELOCITY;
			break;

		case SDLK_LEFT:
			((OverworldGraph*)this->graph)->x= ((OverworldGraph*)this->graph)->x -Player::VELOCITY;
			break;

		case SDLK_RIGHT:*/
			//}
			//break;
		//}
	}
}

void OverWorldLogic::handleEvent(const Uint8* keys)
{

	if (keys[SDL_SCANCODE_RIGHT])
	{
		/*switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			((OverworldGraph*)this->graph)->y= ((OverworldGraph*)this->graph)->y -Player::VELOCITY;
			break;

		case SDLK_DOWN:
			((OverworldGraph*)this->graph)->y = ((OverworldGraph*)this->graph)->y + Player::VELOCITY;
			break;

		case SDLK_LEFT:
			((OverworldGraph*)this->graph)->x= ((OverworldGraph*)this->graph)->x -Player::VELOCITY;
			break;

		case SDLK_RIGHT:*/
		//((OverworldGraph*)this->graph)->x = ((OverworldGraph*)this->graph)->x + Player::VELOCITY;
		//this->player->currentFrame++;
		//if (this->player->currentFrame / 4 >= this->player->FRAMES)
		{
			//this->player->currentFrame = 0;
		}
		//break;
	//}
	}
}
