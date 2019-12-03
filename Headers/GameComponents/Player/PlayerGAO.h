#pragma once
#include "../../CoreComponents/MTT_GraphicalAnimatedObject.h"

namespace Animations {
	enum class Player_Anims { WALKING_LEFT, WALKING_RIGHT, WALKING_UP, WALKING_DOWN, IDLE };
}


class PlayerGAO : public MTT_GraphicalAnimatedObject{
public:
	PlayerGAO() : MTT_GraphicalAnimatedObject() {};
	PlayerGAO(int x, int y) : MTT_GraphicalAnimatedObject(x, y) {};
	PlayerGAO(int* x, int* y) : MTT_GraphicalAnimatedObject(x, y) {};


	int* x = NULL;
	int* y = NULL;

	Animations::Player_Anims currentAnimation = Animations::Player_Anims::IDLE;
	int currentAnimationFrame = 0;
	int speedAnimation = 1; 

	int walkingLeftFrames[1] = {};
	int walkingRightFrames[1] = {};
	int walkingUpFrames[1] = {};
	int walkingDownFrames[1] = {};
	int idleFrames[1] = {};

	void loadSpriteFromFilename(std::string filename);
	void render();



protected:
	MTT_SpriteSheet* spriteSheetTexture = NULL;
	std::vector<SDL_Rect> spritesArea;

	void cutTexture();

};