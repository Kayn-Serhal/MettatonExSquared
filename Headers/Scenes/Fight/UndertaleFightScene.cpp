#include "UndertaleFightScene.h"

void UndertaleFightScene::update()
{
	this->graphical->update();
}

void UndertaleFightScene::free()
{
	delete this->enemy;
}
