#include "../../Headers/CoreComponents/MTT_GraphicalObject.h"

MTT_GraphicalObject::MTT_GraphicalObject() {
	this->x = 0;
	this->y = 0;
	this->hitbox.x = x;
	this->hitbox.y = y;
}

MTT_GraphicalObject::MTT_GraphicalObject(int x, int y)
{
	this->x = x;
	this->y = y;
	this->hitbox.x = x;
	this->hitbox.y = y;
}

bool MTT_GraphicalObject::interact()
{
	return false;
	//Nothing happens if the function isn't OVERLOADED. 
}


