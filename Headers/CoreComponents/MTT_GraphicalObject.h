#pragma once
#include "MTT_Texture.h"
#include <string>
#include <vector>
#include "../Graph/Camera.h"


enum Orientation {NORTH,EAST,WEST,SOUTH, UNDEFINED};

class MTT_GraphicalObject {

public:

	MTT_GraphicalObject();
	MTT_GraphicalObject(int x, int y);
	
	int x;
	int y;

	Orientation orientation;

	SDL_Rect hitbox = { 0,0,0,0 }; //kind of

	std::vector<std::string> textualInteractions;	//The shit the thing is going to say in the overworld. Each string represents a part of the message.
													//Empty if no interactions are available.
	int indexTextualInteractions;

	virtual void render(Camera cam) = 0;
	virtual bool interact(); //Interact like a boss if there is something to do, return false if the object is not interactable.

};
