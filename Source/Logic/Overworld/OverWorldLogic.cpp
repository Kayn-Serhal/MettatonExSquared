#include "../../../Headers/Logic/Overworld/OverWorldLogic.h"
#include "../../../Headers/Graph/Overworld/OverworldGraph.h"


void OverWorldLogic::handleEvent(const Uint8* keys)
{


	if (keys[SDL_SCANCODE_RIGHT])
	{
		//((OverworldGraph*)this->graph)->x = ((OverworldGraph*)this->graph)->x + Player::VELOCITY;
		this->player->moveRight();
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_RIGHT;
	}

	else if (keys[SDL_SCANCODE_LEFT])
	{
		this->player->moveLeft();
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_LEFT;
	}

	else if (keys[SDL_SCANCODE_UP])
	{
		this->player->moveUp();
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_UP;
	}

	else if (keys[SDL_SCANCODE_DOWN])
	{
		this->player->moveDown();
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_DOWN;
	}

	else this->player->playerGraphic.currentAnimation = Animations::Player_Anims::IDLE;
}

void OverWorldLogic::free()
{
	//nothing to free.
}



