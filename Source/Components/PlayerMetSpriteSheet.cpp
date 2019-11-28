#include "../../Headers/Components/SpriteSheet/PlayerMetSpriteSheet.h"
#include "../../Headers/GraphicHandler.h"
#include <string>

void PlayerMetSpriteSheet::loadTexture()
{
	this->spriteSheetTexture.loadFromFile("Kris.png", GraphicHandler::gameRenderer);
}

void PlayerMetSpriteSheet::cutTexture()
{
	
}