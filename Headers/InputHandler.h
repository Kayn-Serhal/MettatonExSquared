#pragma once
#include "GameStateHandler.h"
#include <SDL.h>
#include "../Headers/Logic/Logic.h"
class InputHandler {


public:
	 void handleHighPrecisionEvent(const Uint8* keys);	//High precision used for moving around and shit like that
	 void handleLowPrecisionEvent(SDL_Event e);	// Low precision used for menus, interactions, you know
	 void setCurrentLogic(Logic* newLogic);

private:
	 Logic* currentLogic = NULL;

};


namespace Inputs
{
	extern InputHandler inputHandler;
}



