#include "../../../Headers/GameComponents/Player/PlayerGAO.h"


void PlayerGAO::loadSpriteSheetFromFilename(std::string filename)
{
	this->playerSpriteSheet->loadTexture(filename);

}

void PlayerGAO::fillFramesArrays()
{
	for (int i = 0; i < 12; i++)
	{
		this->walkingRightFrames[i] = this->playerSpriteSheet->spriteForIndex(i);
		this->walkingDownFrames[i] = this->playerSpriteSheet->spriteForIndex(i+12);
		this->walkingLeftFrames[i] = this->playerSpriteSheet->spriteForIndex(i + 24);
		this->walkingUpFrames[i] = this->playerSpriteSheet->spriteForIndex(i + 36);
	}
	this->idleFrames[0] = this->playerSpriteSheet->spriteForIndex(16);
}

void PlayerGAO::render()
{
	this->playerSpriteSheet->render(*x, *y, spriteAreaToDisplay());
	this->currentAnimationFrame++;
	if (this->currentAnimationFrame > 11)
		this->currentAnimationFrame = 0;
}

SDL_Rect* PlayerGAO::spriteAreaToDisplay()
{
	switch (currentAnimation)
	{
	case Animations::Player_Anims::WALKING_DOWN:
		return walkingDownFrames[currentAnimationFrame/speedAnimation];

	case Animations::Player_Anims::WALKING_LEFT:
		return walkingLeftFrames[currentAnimationFrame/speedAnimation];

	case Animations::Player_Anims::WALKING_RIGHT:
		return walkingRightFrames[currentAnimationFrame/speedAnimation];

	case Animations::Player_Anims::WALKING_UP:
		return walkingUpFrames[currentAnimationFrame/speedAnimation];

	default:
		return idleFrames[0];
	}
}
