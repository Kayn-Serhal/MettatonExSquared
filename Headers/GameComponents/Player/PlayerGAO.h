#pragma once
#include "../../CoreComponents/MTT_GraphicalAnimatedObject.h"
#include "Player_SpriteSheet.h"

namespace Animations {
	enum class Player_Anims { WALKING_LEFT, WALKING_RIGHT, WALKING_UP, WALKING_DOWN, IDLE };
}


class PlayerGAO : public MTT_GraphicalAnimatedObject{
public:
	PlayerGAO() : MTT_GraphicalAnimatedObject() { this->playerSpriteSheet = new Player_SpriteSheet(); this->playerSpriteSheet->cutTexture(); this->fillFramesArrays(); };
	PlayerGAO(int x, int y) : MTT_GraphicalAnimatedObject(x, y) { this->playerSpriteSheet = new Player_SpriteSheet(); this->playerSpriteSheet->cutTexture(); this->fillFramesArrays(); };
	PlayerGAO(int* x, int* y) : MTT_GraphicalAnimatedObject(x, y) { this->playerSpriteSheet = new Player_SpriteSheet(); this->playerSpriteSheet->cutTexture(); this->fillFramesArrays(); };


	int* x = NULL;
	int* y = NULL;

	Animations::Player_Anims currentAnimation = Animations::Player_Anims::WALKING_RIGHT;// Change the value of this and the animation will update during rendering. Life is great


	/*_________All Frames_______________*/
	SDL_Rect* walkingLeftFrames[12] = {};
	SDL_Rect* walkingRightFrames[12] = {};
	SDL_Rect* walkingUpFrames[12] = {};
	SDL_Rect* walkingDownFrames[12] = {};
	SDL_Rect* idleFrames[1] = {};

	void fillFramesArrays();
	void render();

protected:
	Player_SpriteSheet* playerSpriteSheet = NULL;
	std::vector<SDL_Rect> spritesArea;

private:
	SDL_Rect* spriteAreaToDisplay();
	int currentAnimationFrame = 0;
	int refreshRate = 200; //The bigger this shit is, the slower the animation will run

};