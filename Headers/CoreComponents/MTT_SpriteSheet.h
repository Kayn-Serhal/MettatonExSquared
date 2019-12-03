#pragma once
#include "MTT_Texture.h"
#include <vector>
class MTTSpriteSheet {

public:
	virtual void loadTexture() = 0;
	virtual void cutTexture() = 0;
	virtual SDL_Rect* spriteForIndex(int index) = 0;
	MTT_Texture* spriteSheetTexture;

protected:

	
	std::vector<SDL_Rect*>spriteFrames;
};