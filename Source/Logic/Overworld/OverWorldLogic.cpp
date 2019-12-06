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
		//((OverworldGraph*)this->graph)->x = ((OverworldGraph*)this->graph)->x + Player::VELOCITY;
		this->player->x++;
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_RIGHT;
	}

	else if (keys[SDL_SCANCODE_LEFT])
	{
		this->player->x--;
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_LEFT;
	}

	else if (keys[SDL_SCANCODE_UP])
	{
		this->player->y--;
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_UP;
	}

	else if (keys[SDL_SCANCODE_DOWN])
	{
		this->player->y++;
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_DOWN;
	}

	else this->player->playerGraphic.currentAnimation = Animations::Player_Anims::IDLE;
}



