#include "../Headers/InputHandler.h"

void InputHandler::handleEvent(SDL_Event e)
{
	InputHandler::currentLogic->handleEvent(e);
}

void InputHandler::setCurrentLogic(Logic* newLogic)
{
	InputHandler::currentLogic = newLogic;
}

Logic* InputHandler::currentLogic = 0;
