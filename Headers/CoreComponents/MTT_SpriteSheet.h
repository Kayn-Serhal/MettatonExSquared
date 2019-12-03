#pragma once
#include "MTT_Texture.h"
#include <vector>
class MTT_SpriteSheet {

public:
	virtual void loadTexture() = 0;
	virtual void cutTexture() = 0;
	virtual SDL_Rect* spriteForIndex(int index) = 0;

	int numberOfSprites();


protected:
	std::vector<SDL_Rect*>spriteFrames;

private:

	MTT_Texture* spriteSheetTexture;

};