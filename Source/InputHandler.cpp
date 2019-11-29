#include "../Headers/InputHandler.h"

void InputHandler::handleEvent(SDL_Event e)
{
	InputHandler::currentLogic->handleEvent(e);
}

void InputHandler::handleEvent(const Uint8* keys)
{
	InputHandler::currentLogic->handleEvent(keys);
}

void InputHandler::setCurrentLogic(Logic* newLogic)
{
	InputHandler::currentLogic = newLogic;
}

Logic* InputHandler::currentLogic = 0;
