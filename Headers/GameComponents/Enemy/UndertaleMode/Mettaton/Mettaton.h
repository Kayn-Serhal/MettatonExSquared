#pragma once
#include "../UndertaleEnemy.h"
class Mettaton : UndertaleEnemy{

	Mettaton(MettatonGAO* metGAO) :UndertaleEnemy() {};
	void attack(SDL_Renderer* renderer, int turn);




};