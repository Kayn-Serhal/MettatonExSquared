#include "../../Headers/CoreComponents/MTT_GraphicalObject.h"

MTTGraphicalObject::MTTGraphicalObject() {
	this->x = 0;
	this->y = 0;
}

MTTGraphicalObject::MTTGraphicalObject(int x, int y)
{
	this->x = &x;
	this->y = &y;
}

MTTGraphicalObject::MTTGraphicalObject(int* x, int* y)
{
	this->x = x;
	this->y = y;
}

