#pragma once
#include "MetGraphicalObject.h"

class MetGraphicalStaticObject: public MetGraphicalObject {
public:

	MetGraphicalStaticObject() :MetGraphicalObject() {};
	MetGraphicalStaticObject(int x, int y) :MetGraphicalObject(x, y) {  };

	int x = 0;
	int y = 0;

	void loadSpriteFromFilename(std::string filename);
	void render();


protected:
	MetTexture spriteTexture;
};