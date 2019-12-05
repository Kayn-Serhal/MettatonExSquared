#pragma once
#include "../../CoreComponents/MTT_SpriteSheet.h"
class Player_SpriteSheet : public MTT_SpriteSheet {

public:
	Player_SpriteSheet();
	void cutTexture();
	void render(int x, int y, SDL_Rect* spriteArea);


protected:
	std::vector<SDL_Rect*>spriteFrames;
	MTT_Texture* spriteSheetTexture = NULL;

};