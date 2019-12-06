#pragma once
#include "../../CoreComponents/MTT_SpriteSheet.h"
class Player_SpriteSheet : public MTT_SpriteSheet {

public:
	Player_SpriteSheet();
	void loadTexture(std::string filename);
	SDL_Rect* spriteForIndex(int index);
	void cutTexture();
	void render(int x, int y, SDL_Rect* spriteArea, Camera cam);


protected:
	std::vector<SDL_Rect*>spriteFrames;
	MTT_Texture* spriteSheetTexture = NULL;

};