#pragma once
#include "MTT_Texture.h"
#include <string>

namespace Animations {
	enum class Ron{WALK};
}

class MTT_GraphicalObject {

public:

	MTT_GraphicalObject();
	MTT_GraphicalObject(int x, int y);
	MTT_GraphicalObject(int* x, int* y);
	
	int* x = NULL;
	int* y = NULL;

	virtual void loadSpriteFromFilename(std::string filename) = 0;
	virtual void render() = 0;


};
