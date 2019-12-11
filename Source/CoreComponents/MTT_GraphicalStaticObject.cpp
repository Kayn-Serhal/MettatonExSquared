#include "../../Headers/CoreComponents/MTT_GraphicalStaticObject.h"
#include "../../Headers/GraphicHandler.h"

void MTT_GraphicalStaticObject::loadSpriteFromFilename(std::string filename)
{
	spriteTexture.loadFromFile(filename, Graphics::graphicHandler.gameRenderer);
	this->box.h = spriteTexture.getHeight();
	this->box.w = spriteTexture.getWidth();
}

void MTT_GraphicalStaticObject::render(Camera cam)
{
	this->spriteTexture.render(this->x -cam.x, this->y-cam.y, NULL, Graphics::graphicHandler.gameRenderer);
}
