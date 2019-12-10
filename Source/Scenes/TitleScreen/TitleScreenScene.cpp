#include "../../../Headers/Scenes/TitleScreen/TitleScreenScene.h"


void TitleScreenScene::free()
{
	this->graphical->free();
	this->logical->free();
	delete this->graphical;
	delete this->logical;
}
