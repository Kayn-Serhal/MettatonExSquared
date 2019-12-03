#pragma once
#include "MTT_GraphicalObject.h"

class MTT_GraphicalStaticObject: public MTT_GraphicalObject {
public:

	MTT_GraphicalStaticObject() :MTT_GraphicalObject() {};
	MTT_GraphicalStaticObject(int x, int y) :MTT_GraphicalObject(x, y) {  };
	MTT_GraphicalStaticObject(int* x, int* y) : MTT_GraphicalObject(x, y) {};

	int* x = NULL;
	int* y = NULL;

	void loadSpriteFromFilename(std::string filename);
	void render();


protected:
	MTT_Texture spriteTexture;
};