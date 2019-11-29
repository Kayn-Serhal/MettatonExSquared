#include "../../Headers/Components/Player.h"


Player::Player()
{
	this->spriteSheet = new PlayerMetSpriteSheet();
	this->spriteSheet->loadTexture();
	this->x = 0;
	this->y = 0;
}

Player::Player(int x, int y)
{
	this->spriteSheet = new PlayerMetSpriteSheet();
	this->spriteSheet->loadTexture();
	this->x = x;
	this->y = y;
}

MetTexture* Player::currentSpriteSheetTexture()
{
	return this->spriteSheet->spriteSheetTexture;
}

SDL_Rect* Player::methodeTest(int i)
{
	return this->spriteSheet->spriteForIndex(i);
}
