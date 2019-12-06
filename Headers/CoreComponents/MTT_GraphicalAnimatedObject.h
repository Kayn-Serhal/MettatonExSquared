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

	virtual void render() = 0;

protected : 
	
	MTT_SpriteSheet* spriteSheetTexture = NULL;
};