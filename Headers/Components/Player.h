#pragma once
#include "MTT_SpriteSheet.h"

class Player {

public :

	static const int VELOCITY = 1;
	static const int FRAMES = 4;
	
	Player();

	Player(int x, int y);




protected : 

	int x;
	int y;

};