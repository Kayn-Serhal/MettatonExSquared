#pragma once
#include "PlayerGAO.h"

class Player {

public :

	const int VELOCITY = 6; //2 is fine but i'm debugging right now.
	
	Player();

	Player(int x, int y);

	void moveUp();

	void moveDown();

	void moveLeft();

	void moveRight();



	PlayerGAO playerGraphic;

	int x;
	int y;

	bool loadingZoneLifeInsurance = false; // This boolean is here in order to prevent the player to get stuck if imprecisions in the destinationx or destination y 
											 //Of loading areas made the player spawn in a loadingarea itself.

};