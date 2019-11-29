#pragma once
#include "MetSpriteSheet.h"
#include "../../Headers/Components/SpriteSheet/PlayerMetSpriteSheet.h"

class Player {

public :

	static const int VELOCITY = 1;
	static const int FRAMES = 12;
	
	Player();

	Player(int x, int y);

	int currentFrame = 0;

	MetTexture* currentSpriteSheetTexture();

	SDL_Rect* methodeTest(int i);
protected : 

	int x;
	int y;

	PlayerMetSpriteSheet* spriteSheet;
};