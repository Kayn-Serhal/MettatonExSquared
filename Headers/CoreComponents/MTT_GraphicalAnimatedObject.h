#pragma once
#include "MTT_GraphicalObject.h"
#include "MTT_SpriteSheet.h"
#include <vector>

class MTT_GraphicalAnimatedObject: public MTT_GraphicalObject {

public:

	MTT_GraphicalAnimatedObject() : MTT_GraphicalObject() {};
	MTT_GraphicalAnimatedObject(int x, int y) : MTT_GraphicalObject(x, y) {};
	MTT_GraphicalAnimatedObject(int* x, int* y) : MTT_GraphicalObject(x, y) { };

	int* x = NULL;
	int* y = NULL;

	void loadSpriteFromFilename(std::string filename) = 0;
	virtual void render() = 0;

protected : 
	
	virtual void cutTexture() = 0;  //Fills the spritesArea attribute by cutting the spriteSheetTexture in a socially acceptable and easily animatable. This word exists. I checked
	MTT_SpriteSheet* spriteSheetTexture = NULL;
	std::vector<SDL_Rect> spritesArea;	//This, my son, is a vector containing a fuckton of SDL_Rect.
										//Those SDL_Rect will represent an area of the spritesheet that we're going to render
										//When necessary
};