#pragma once
#include "GameStateHandler.h"
#include <SDL.h>
#include "../Headers/Logic/Logic.h"
class InputHandler {


public:
	 void handleEvent(const Uint8* keys);
	 void setCurrentLogic(Logic* newLogic);

private:
	 Logic* currentLogic = NULL;

};


namespace Inputs
{
	extern InputHandler inputHandler;
}



