#pragma once
#include "../MetSpriteSheet.h"

class PlayerMetSpriteSheet : public MetSpriteSheet
{
public : 
	PlayerMetSpriteSheet();
	void loadTexture();
	void cutTexture();
	SDL_Rect* spriteForIndex(int index);
	MetTexture* spriteSheetTexture;

};