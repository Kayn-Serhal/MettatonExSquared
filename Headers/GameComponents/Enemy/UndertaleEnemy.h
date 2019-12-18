#pragma once
#include "../../CoreComponents/MTT_GraphicalAnimatedObject.h"
class UndertaleEnemy {


public:
	virtual void attack() = 0;


	MTT_GraphicalAnimatedObject* GAO;

private:

	int HP;
	int maxHP;

};
