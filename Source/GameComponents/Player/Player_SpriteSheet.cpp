#include "../../../Headers/GameComponents/Player/Player_SpriteSheet.h"

Player_SpriteSheet::Player_SpriteSheet() {
	this->spriteSheetTexture = new MTT_Texture();
}
void Player_SpriteSheet::cutTexture()
{
	int horizontal = 0;
	int vertical = 0;

	for (vertical; vertical < 4; vertical++)
	{ 
		for (horizontal; horizontal < 12; horizontal++)
		{
			SDL_Rect* spriteArea = new SDL_Rect();
			spriteArea->h = 60;
			spriteArea->w = 50;
			spriteArea->x = horizontal * 50;
			spriteArea->y = vertical * 60;
			this->spriteFrames.push_back(spriteArea);
		}
	}
}

void Player_SpriteSheet::render(int x, int y, SDL_Rect* spriteArea)
{
	this->spriteSheetTexture->render(x, y, spriteArea, Graphics::graphicHandler.gameRenderer);
}


