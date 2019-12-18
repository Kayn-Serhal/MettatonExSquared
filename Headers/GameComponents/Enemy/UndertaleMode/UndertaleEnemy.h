#pragma once
#include "../../../CoreComponents/MTT_GraphicalAnimatedObject.h"
class UndertaleEnemy {


public:
	UndertaleEnemy();
	virtual void attack(SDL_Renderer* renderer) = 0;


	MTT_GraphicalAnimatedObject* GAO;

protected:

	int HP;
	int maxHP;

};
