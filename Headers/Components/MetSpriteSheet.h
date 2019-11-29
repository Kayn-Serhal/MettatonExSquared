#pragma once
#include "MetTexture.h"
#include <vector>
class MetSpriteSheet {

public:
	virtual void loadTexture() = 0;
	virtual void cutTexture() = 0;
	virtual SDL_Rect* spriteForIndex(int index) = 0;
	MetTexture* spriteSheetTexture;

protected:

	
	std::vector<SDL_Rect*>spriteFrames;
};