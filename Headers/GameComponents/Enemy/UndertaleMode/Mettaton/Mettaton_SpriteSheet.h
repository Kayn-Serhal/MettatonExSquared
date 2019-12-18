#pragma once
#include "../../../../CoreComponents/MTT_SpriteSheet.h"
class Mettaton_SpriteSheet : public MTT_SpriteSheet {
	

public : 
	Mettaton_SpriteSheet();
	void loadTexture(std::string filename);
	SDL_Rect* spriteForIndex(int index);
	void cutTexture();
	void render(int x, int y, SDL_Rect* spriteArea, Camera cam);

};