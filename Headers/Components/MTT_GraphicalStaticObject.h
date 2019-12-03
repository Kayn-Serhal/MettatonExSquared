#pragma once
#include "MTT_GraphicalObject.h"

class MTT_GraphicalStaticObject: public MTTGraphicalObject {
public:

	MTT_GraphicalStaticObject() :MTTGraphicalObject() {};
	MTT_GraphicalStaticObject(int x, int y) :MTTGraphicalObject(x, y) {  };
	MTT_GraphicalStaticObject(int* x, int* y) : MTTGraphicalObject(x, y) {};

	int* x = NULL;
	int* y = NULL;

	void loadSpriteFromFilename(std::string filename);
	void render();


protected:
	MTT_Texture spriteTexture;
};