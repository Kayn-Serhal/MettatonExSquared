#pragma once
#include "MetTexture.h"
#include <string>

class MetGraphicalObject {

public:

	MetGraphicalObject();
	MetGraphicalObject(int x, int y);
	
	int x;
	int y;

	virtual void loadSpriteFromFilename(std::string filename) = 0;
	virtual void render() = 0;


};
