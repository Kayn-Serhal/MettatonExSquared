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


	void loadSpriteFromFilename(std::string filename);
	void render();

protected:
	MTT_SpriteSheet* spriteSheetTexture = NULL;
	std::vector<SDL_Rect> spritesArea;

	void cutTexture();

};