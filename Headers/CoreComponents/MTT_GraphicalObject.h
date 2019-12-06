#pragma once
#include "MTT_Texture.h"
#include <string>
#include "../Graph/Camera.h"


class MTT_GraphicalObject {

public:

	MTT_GraphicalObject();
	MTT_GraphicalObject(int x, int y);
	MTT_GraphicalObject(int* x, int* y);
	
	int* x = NULL;
	int* y = NULL;
	virtual void render(Camera cam) = 0;

};
