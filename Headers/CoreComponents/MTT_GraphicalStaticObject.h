#pragma once
#include "MTT_GraphicalObject.h"

class MTT_GraphicalStaticObject: public MTT_GraphicalObject {
public:

	MTT_GraphicalStaticObject() :MTT_GraphicalObject() {};
	MTT_GraphicalStaticObject(int x, int y) :MTT_GraphicalObject(x, y) { this->hitbox.x = x; this->hitbox.y = y; };

	void loadSpriteFromFilename(std::string filename);
	void render(Camera cam);


protected:
	MTT_Texture spriteTexture;
};