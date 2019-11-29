#pragma once
#include "MetSpriteSheet.h"
#include "../../Headers/Components/SpriteSheet/PlayerMetSpriteSheet.h"

class Player {

public :

	const int VELOCITY = 10;
	
	Player();

	Player(int x, int y);

	MetTexture* currentSpriteSheetTexture();

	SDL_Rect* methodeTest(int i);
protected : 

	int x;
	int y;

	PlayerMetSpriteSheet* spriteSheet;
};