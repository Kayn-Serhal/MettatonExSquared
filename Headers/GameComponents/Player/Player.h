#pragma once
#include "PlayerGAO.h"

class Player {

public :

	static const int VELOCITY = 1;
	static const int FRAMES = 4;
	
	Player();

	Player(int x, int y);

	void moveUp();

	void moveDown();

	void moveLeft();

	void moveRight();

	PlayerGAO playerGraphic;


protected : 

	int x;
	int y;

};