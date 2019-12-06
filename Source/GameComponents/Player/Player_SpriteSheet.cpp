#include "../../../Headers/GameComponents/Player/Player_SpriteSheet.h"

Player_SpriteSheet::Player_SpriteSheet() {
	this->spriteSheetTexture = new MTT_Texture();
	spriteSheetTexture->loadFromFile("Susie.png",Graphics::graphicHandler.gameRenderer);
	this->cutTexture();
}
void Player_SpriteSheet::loadTexture(std::string filename)
{
	spriteSheetTexture->loadFromFile(filename, Graphics::graphicHandler.gameRenderer);
	this->cutTexture();
}

SDL_Rect* Player_SpriteSheet::spriteForIndex(int index)
{
	return this->spriteFrames.at(index);
}

void Player_SpriteSheet::cutTexture()
{
	int horizontal = 0;
	int vertical = 0;

	for (vertical; vertical < 4; vertical++)
	{ 
		for (horizontal = 0; horizontal < 12; horizontal++)
		{
			SDL_Rect* spriteArea = new SDL_Rect();
			spriteArea->h = 51;
			spriteArea->w = 35;
			spriteArea->x = horizontal * 35;
			spriteArea->y = vertical * 51;
			this->spriteFrames.push_back(spriteArea);
		}
	}
}

void Player_SpriteSheet::render(int x, int y, SDL_Rect* spriteArea)
{
	this->spriteSheetTexture->render(x, y, spriteArea, Graphics::graphicHandler.gameRenderer);
}


