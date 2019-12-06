#include "../../Headers/CoreComponents/MTT_SpriteSheet.h"

void MTT_SpriteSheet::loadTexture(std::string filename)
{
	spriteSheetTexture->loadFromFile(filename,Graphics::graphicHandler.gameRenderer);
}

SDL_Rect* MTT_SpriteSheet::spriteForIndex(int index)
{
	return this->spriteFrames.at(index);
}

int MTT_SpriteSheet::numberOfSprites()
{
	return this->spriteFrames.size();
}
