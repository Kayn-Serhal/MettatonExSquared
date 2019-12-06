#pragma once
#include "MTT_Texture.h"
#include "../GraphicHandler.h"
#include <vector>
class MTT_SpriteSheet {

public:
	void loadTexture(std::string filename);
	virtual void cutTexture() = 0;
	SDL_Rect* spriteForIndex(int index);
	virtual void render(int x, int y, SDL_Rect* spriteArea,Camera cam) = 0;

	int numberOfSprites();


protected:
	std::vector<SDL_Rect*>spriteFrames;
	MTT_Texture* spriteSheetTexture;

};