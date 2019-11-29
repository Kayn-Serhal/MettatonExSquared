#include "../../Headers/Components/SpriteSheet/PlayerMetSpriteSheet.h"
#include "../../Headers/GraphicHandler.h"
#include <string>

PlayerMetSpriteSheet::PlayerMetSpriteSheet()
{
	this->spriteSheetTexture = new MetTexture();
}

void PlayerMetSpriteSheet::loadTexture()
{
	spriteSheetTexture->loadFromFile("Kris.png", GraphicHandler::gameRenderer);
	this->cutTexture();
}

void PlayerMetSpriteSheet::cutTexture()
{

	


	//Placeholder designed for tests. It needs to change later
	for (int vertical = 0; vertical < 4; vertical++)
	{

		SDL_Rect* rectSprite = new SDL_Rect();

		rectSprite->h = 50;
		rectSprite->w = 468 / 12;
		rectSprite->y = vertical * rectSprite->h;
		for (int horizontal = 0; horizontal < 12; horizontal++)
		{
			rectSprite->x = horizontal * rectSprite->w;
			this->spriteFrames.push_back(rectSprite);
		}
	}
}

SDL_Rect* PlayerMetSpriteSheet::spriteForIndex(int index)
{
	return this->spriteFrames.at(index);
}

