#pragma once
#include "MetSpriteSheet.h"

class Player {

public :

	const int VELOCITY = 10;
	
	Player();

	Player(int x, int y);

protected : 

	int x;
	int y;

	MetSpriteSheet* spriteSheet;
};