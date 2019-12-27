#include "../../../Headers/Logic/Overworld/OverWorldLogic.h"
#include "../../../Headers/Graph/Overworld/OverworldGraph.h"
#include "../../../Headers/GameLoader.h"


//When refactoring time is gonna come, this will hit hard.
//An idea could be to divise methods depending on the player status...?
//I know, i'm supposed to think before coding.

//But obviously, i ain't doing this.

void OverWorldLogic::handleHighPrecisionEvent(const Uint8* keys)
{

	SDL_Rect testHitboxForCollision = this->player->playerGraphic.hitbox;
	bool playerCanMove = player->currentStatus!= PlayerOverworldStatus::TALKING_OR_EXAMINING ||player->currentStatus == PlayerOverworldStatus::IDLE; //This is kind of rocky.
																							  //Let's test it that way and change it afterwards when interactions works.
	if (playerCanMove) {
		if (keys[SDL_SCANCODE_RIGHT])
		{
			testHitboxForCollision.x += player->VELOCITY;
			for (const auto& asset : ((OverworldGraph*)this->graph)->areaAssets)
			{
				if (checkCollisionsBetweenTwoRectangles(testHitboxForCollision, asset->hitbox)) playerCanMove = false;
				this->player->playerGraphic.currentAnimation = Animations::Player_Anims::IDLE;
				this->player->currentStatus = PlayerOverworldStatus::IDLE;
			}

			if (playerCanMove) {
				this->player->moveRight();
				this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_RIGHT;
				this->player->currentStatus = PlayerOverworldStatus::WALKING;//putting that in player could be a good idea	
			}
		}

		else if (keys[SDL_SCANCODE_LEFT])
		{

			testHitboxForCollision.x -= player->VELOCITY;
			for (const auto& asset : ((OverworldGraph*)this->graph)->areaAssets)
			{
				if (checkCollisionsBetweenTwoRectangles(testHitboxForCollision, asset->hitbox)) playerCanMove = false;
				this->player->playerGraphic.currentAnimation = Animations::Player_Anims::IDLE;
				this->player->currentStatus = PlayerOverworldStatus::IDLE;
			}

			if (playerCanMove)
			{
				this->player->moveLeft();
				this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_LEFT;
				this->player->currentStatus = PlayerOverworldStatus::WALKING;
			}
		}

		else if (keys[SDL_SCANCODE_UP])
		{

			testHitboxForCollision.y -= player->VELOCITY;
			for (const auto& asset : ((OverworldGraph*)this->graph)->areaAssets)
			{
				if (checkCollisionsBetweenTwoRectangles(testHitboxForCollision, asset->hitbox)) playerCanMove = false;
				this->player->playerGraphic.currentAnimation = Animations::Player_Anims::IDLE;
				this->player->currentStatus = PlayerOverworldStatus::IDLE;
			}

			if (playerCanMove) {
				this->player->moveUp();
				this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_UP;
				this->player->currentStatus = PlayerOverworldStatus::WALKING;
			}
		}

		else if (keys[SDL_SCANCODE_DOWN])
		{
			testHitboxForCollision.y += player->VELOCITY;
			for (const auto& asset : ((OverworldGraph*)this->graph)->areaAssets)
			{
				if (checkCollisionsBetweenTwoRectangles(testHitboxForCollision, asset->hitbox)) playerCanMove = false;
				{
					this->player->playerGraphic.currentAnimation = Animations::Player_Anims::IDLE;
					this->player->currentStatus = PlayerOverworldStatus::IDLE;
				}
			}
			if (playerCanMove) {
				this->player->moveDown();
				this->player->playerGraphic.currentAnimation = Animations::Player_Anims::WALKING_DOWN;
			}
		}

		else {
			this->player->playerGraphic.currentAnimation = Animations::Player_Anims::IDLE;
			this->player->currentStatus = PlayerOverworldStatus::IDLE;
		}

		this->checkIfPlayerInLoadingArea();
	}
}

void OverWorldLogic::handleLowPrecisionEvent(SDL_Event e)
{
	if (player->currentStatus != PlayerOverworldStatus::TALKING_OR_EXAMINING) 
	{
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_e)
		this->checkIfInteractableObjectInFrontOfPlayer();
	}
	else
	{
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_e)
		{
			printf("WOOH, woh woh WOOOH");
			player->currentStatus = PlayerOverworldStatus::IDLE;
		}
	}
}



void OverWorldLogic::free()
{
	//nothing to free, yet.
}

bool OverWorldLogic::checkIfPlayerColliding(MTT_GraphicalObject* object)
{
	if (object) {

		if (checkCollisionsBetweenTwoRectangles(this->player->playerGraphic.hitbox, object->hitbox))
		{
			return true;
		}
	}
}


//STAY VIGILANT:
//If you start fucking around and load stuff, it's great ;
//It's what a game is supposed to do.
//However.
//do NOT ever load anything when you're in a loop.
//Cuz you know, loading things mean deleting the old thing
//And you don't want to keep processing shit in a deleted thing.
//Believe me, you don't want this.
//That's the reason why we have two local variables before.
void OverWorldLogic::checkIfPlayerInLoadingArea()
{


	bool hasReachedLoadingZone = false;
	MTT_LoadingArea loadingArea;

	for (std::vector<MTT_LoadingArea>::iterator it = ((OverworldGraph*)this->graph)->loadingAreas.begin(); it != ((OverworldGraph*)this->graph)->loadingAreas.end(); it++)
	{
		if (checkCollisionsBetweenTwoRectangles(this->player->getHitbox(), it->loadingAreaCoordinates))
		{
			hasReachedLoadingZone = true;
			loadingArea.loadingAreaCoordinates = it->loadingAreaCoordinates;
			loadingArea.zoneOfDestination = it->zoneOfDestination;
			loadingArea.subZoneOfDestination = it->subZoneOfDestination;
			loadingArea.destinationX = it->destinationX;
			loadingArea.destinationY = it->destinationY;
		}
	}

	if (hasReachedLoadingZone & !player->loadingZoneLifeInsurance)
	{
		player->setX(loadingArea.destinationX);
		player->setY(loadingArea.destinationY);
		player->loadingZoneLifeInsurance = true;
		GameLoader::loadOverworldScene(loadingArea.zoneOfDestination, loadingArea.subZoneOfDestination, player);
	}
	else if (!hasReachedLoadingZone && player->loadingZoneLifeInsurance) player->loadingZoneLifeInsurance = false;
	
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

void OverWorldLogic::checkIfInteractableObjectInFrontOfPlayer()
{

	SDL_Rect checkRect = player->getHitbox();

	switch (player->playerGraphic.orientation) {

	case Orientation::NORTH:
		checkRect.y -= 10;
		break;

	case Orientation::SOUTH:
		checkRect.y += 10;
		break;

	case Orientation::EAST:
		checkRect.x += 10;
		break;

	case Orientation::WEST:
		checkRect.x -= 10;
		break;

	default: break;
	}

	for (const auto& asset : ((OverworldGraph*)this->graph)->areaAssets)
	{
		if (checkCollisionsBetweenTwoRectangles(checkRect, asset->hitbox))
		{
			if (asset->interact())
			{
				player->currentStatus = PlayerOverworldStatus::TALKING_OR_EXAMINING;
			}
		}
	}
}
