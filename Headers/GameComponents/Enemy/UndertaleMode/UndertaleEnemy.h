#pragma once
#include "../../../CoreComponents/MTT_GraphicalAnimatedObject.h"
class UndertaleEnemy {


public:
	UndertaleEnemy() {};
	virtual void attack(SDL_Renderer* renderer, int turn) = 0;


	MTT_GraphicalAnimatedObject* GAO =NULL;

protected:

	int HP =0;
	int maxHP=0;

};
