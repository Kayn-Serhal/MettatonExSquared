#pragma once
#include "../CoreComponents/MTT_GraphicalStaticObject.h"


class Cat : public MTT_GraphicalStaticObject {
public:
	Cat() :MTT_GraphicalStaticObject() { 
		this->loadSpriteFromFilename("Cat.png");
	}
	
	
	;
	Cat(int x, int y) : MTT_GraphicalStaticObject(x, y) {};



	bool interact();

};