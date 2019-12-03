#include "../../Headers/CoreComponents/MTT_GraphicalObject.h"

MTT_GraphicalObject::MTT_GraphicalObject() {
	this->x = 0;
	this->y = 0;
}

MTT_GraphicalObject::MTT_GraphicalObject(int x, int y)
{
	this->x = &x;
	this->y = &y;
}

MTT_GraphicalObject::MTT_GraphicalObject(int* x, int* y)
{
	this->x = x;
	this->y = y;
}

