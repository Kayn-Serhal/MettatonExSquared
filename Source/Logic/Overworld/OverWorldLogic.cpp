#include "../../../Headers/Logic/Overworld/OverWorldLogic.h"
#include "../../../Headers/Graph/Overworld/OverworldGraph.h"


void OverWorldLogic::handleEvent(const Uint8* keys)
{


	if (keys[SDL_SCANCODE_RIGHT])
	{
		//((OverworldGraph*)this->graph)->x = ((OverworldGraph*)this->graph)->x + Player::VELOCITY;
		this->player->x += this->player->VELOCITY;
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_RIGHT;
	}

	else if (keys[SDL_SCANCODE_LEFT])
	{
		this->player->x -= this->player->VELOCITY;
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_LEFT;
	}

	else if (keys[SDL_SCANCODE_UP])
	{
		this->player->y -= this->player->VELOCITY;
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_UP;
	}

	else if (keys[SDL_SCANCODE_DOWN])
	{
		this->player->y += this->player->VELOCITY;
		this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_DOWN;
	}

	else this->player->playerGraphic.currentAnimation = Animations::Player_Anims::IDLE;
}

void OverWorldLogic::free()
{
	//nothing to free.
}



