#include "../../../Headers/Logic/Overworld/OverWorldLogic.h"
#include "../../../Headers/Graph/Overworld/OverworldGraph.h"
#include "../../../Headers/GameLoader.h"


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

	this->checkIfPlayerInLoadingArea();

	

}

void OverWorldLogic::free()
{
	//nothing to free.
}

void OverWorldLogic::checkIfPlayerColliding(MTT_GraphicalObject* object)
{

	//This part sucks and need refactoring 
	SDL_Rect playerRect;

	playerRect.h = this->player->playerGraphic.getSpriteHeight();
	playerRect.w = this->player->playerGraphic.getSpriteWidth();
	playerRect.x = player->x;
	playerRect.y = player->y;

	if (checkCollisionsBetweenTwoRectangles(playerRect, object->box))
	{
		//Do stuff
	}
}

void OverWorldLogic::checkIfPlayerInLoadingArea()
{

	//This part sucks and need refactoring 
	SDL_Rect playerRect;

	playerRect.h = this->player->playerGraphic.getSpriteHeight();
	playerRect.w = this->player->playerGraphic.getSpriteWidth();
	playerRect.x = player->x;
	playerRect.y = player->y;

	if (checkCollisionsBetweenTwoRectangles(playerRect, this->loadingArea))
	{
		GameLoader::loadScene(GamePlayState::OVERWORLD);
	}
}

//Spoiler : it's not mine
bool OverWorldLogic::checkCollisionsBetweenTwoRectangles(SDL_Rect a, SDL_Rect b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }
    return true;
}




