#include "../Headers/InputHandler.h"



void InputHandler::handleHighPrecisionEvent(const Uint8* keys)
{
	Inputs::inputHandler.currentLogic->handleHighPrecisionEvent(keys);
}

void InputHandler::handleLowPrecisionEvent(SDL_Event e)
{
	Inputs::inputHandler.currentLogic->handleLowPrecisionEvent(e);
}

void InputHandler::setCurrentLogic(Logic* newLogic)
{
	Inputs::inputHandler.currentLogic = newLogic;
}

InputHandler Inputs::inputHandler;
