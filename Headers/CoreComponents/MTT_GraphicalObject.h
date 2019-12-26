#pragma once
#include "MTT_Texture.h"
#include <string>
#include "../Graph/Camera.h"


enum Orientation {NORTH,EAST,WEST,SOUTH, UNDEFINED};

class MTT_GraphicalObject {



public:




	MTT_GraphicalObject();
	MTT_GraphicalObject(int x, int y);
	
	int x;
	int y;

	Orientation orientation;

	bool interactable = false;

	SDL_Rect hitbox = { 0,0,0,0 }; //kind of
	std::string dialogue = "";

	virtual void render(Camera cam) = 0;

};
