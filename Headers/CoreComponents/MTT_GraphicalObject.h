#pragma once
#include "MTT_Texture.h"
#include <string>
#include "../Graph/Camera.h"


class MTT_GraphicalObject {

public:

	MTT_GraphicalObject();
	MTT_GraphicalObject(int x, int y);
	
	int x;
	int y;

	SDL_Rect hitbox = { 0,0,0,0 }; //kind of

	virtual void render(Camera cam) = 0;

};
