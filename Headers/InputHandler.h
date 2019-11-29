#pragma once
#include "GameStateHandler.h"
#include <SDL.h>
#include "../Headers/Logic/Logic.h"
class InputHandler {


public:
	static void handleEvent(SDL_Event e);
	static void handleEvent(const Uint8* keys);
	static void setCurrentLogic(Logic* newLogic);

private:
	static Logic* currentLogic;

};



