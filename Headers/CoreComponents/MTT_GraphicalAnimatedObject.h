#pragma once
#include "MTT_GraphicalObject.h"
#include "MTT_SpriteSheet.h"
#include <vector>

class MTT_GraphicalAnimatedObject: public MTT_GraphicalObject {

public:

	MTT_GraphicalAnimatedObject() : MTT_GraphicalObject() {};
	MTT_GraphicalAnimatedObject(int x, int y) : MTT_GraphicalObject(x, y) {};


	virtual void render(Camera cam) = 0;

protected : 
	
	MTT_SpriteSheet* spriteSheetTexture = NULL;
};