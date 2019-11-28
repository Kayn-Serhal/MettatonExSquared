#pragma once
#include "../MetSpriteSheet.h"

class PlayerMetSpriteSheet : public MetSpriteSheet
{
public : 
	void loadTexture();
	void cutTexture();
	MetTexture spriteForIndex();


};