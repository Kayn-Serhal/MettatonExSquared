#pragma once
#include "PlayerGAO.h"

enum class PlayerOverworldStatus {TALKING_OR_EXAMINING, WALKING, IDLE};

//It's going to be one heck of a class! 
class Player {

public :

	const int VELOCITY = 6; //2 is fine but i'm debugging right now.
	
	Player();

	Player(int x, int y);

	void moveUp();

	void moveDown();

	void moveLeft();

	void moveRight();

	SDL_Rect getHitbox();

	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);

	PlayerOverworldStatus currentStatus = PlayerOverworldStatus::IDLE;

	PlayerGAO playerGraphic;

	bool loadingZoneLifeInsurance = false; // This boolean is here in order to prevent the player to get stuck if imprecisions in the destinationx or destination y 
											//Of loading areas made the player spawn in a loadingarea itself.

private:

	int x;
	int y;

};