#pragma once
#include "MTT_Texture.h"
#include <string>

class MTTGraphicalObject {

public:

	MTTGraphicalObject();
	MTTGraphicalObject(int x, int y);
	MTTGraphicalObject(int* x, int* y);
	
	int* x = NULL;
	int* y = NULL;

	virtual void loadSpriteFromFilename(std::string filename) = 0;
	virtual void render() = 0;


};
