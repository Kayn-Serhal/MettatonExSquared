#include "../../Headers/Components/MetGraphicalStaticObject.h"
#include "../../Headers/GraphicHandler.h"

void MetGraphicalStaticObject::loadSpriteFromFilename(std::string filename)
{
	spriteTexture.loadFromFile(filename, GraphicHandler::gameRenderer);
}

void MetGraphicalStaticObject::render()
{
	this->spriteTexture.render(this->x, this->y, NULL, GraphicHandler::gameRenderer);
}
