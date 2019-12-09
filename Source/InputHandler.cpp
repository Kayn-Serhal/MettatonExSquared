#include "../Headers/InputHandler.h"


void InputHandler::handleEvent(const Uint8* keys)
{
	Inputs::inputHandler.currentLogic->handleEvent(keys);
}

void InputHandler::setCurrentLogic(Logic* newLogic)
{
	Inputs::inputHandler.currentLogic = newLogic;
}

InputHandler Inputs::inputHandler;
