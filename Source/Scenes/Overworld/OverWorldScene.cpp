#include "../../../Headers/Scenes/Overworld/OverWorldScene..h"


void OverWorldScene::update()
{
	this->graphical->update();
}

void OverWorldScene::free()
{
	this->graphical->free();
	this->logical->free();
	delete this->graphical;
	delete this->logical;
}
