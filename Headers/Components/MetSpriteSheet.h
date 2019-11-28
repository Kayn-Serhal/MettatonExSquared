#pragma once
#include "MetTexture.h"
#include <vector>
class MetSpriteSheet {

public:
	virtual void loadTexture() = 0;
	virtual void cutTexture() = 0;
	virtual MetTexture spriteForIndex(int index) = 0;


protected:

	MetTexture spriteSheetTexture;
	std::vector<SDL_Rect>spriteFrames;
};