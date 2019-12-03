#include "../../Headers/Components/MTT_GraphicalStaticObject.h"
#include "../../Headers/GraphicHandler.h"

void MTT_GraphicalStaticObject::loadSpriteFromFilename(std::string filename)
{
	spriteTexture.loadFromFile(filename, Graphics::graphicHandler.gameRenderer);
}

void MTT_GraphicalStaticObject::render()
{
	this->spriteTexture.render(*this->x, *this->y, NULL, Graphics::graphicHandler.gameRenderer);
}
