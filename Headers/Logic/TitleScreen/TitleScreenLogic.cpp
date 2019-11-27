#include "TitleScreenLogic.h"

void TitleScreenLogic::handleEvent(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{
		((TitleScreenGraph*)graph)->fuckShitUp();
		printf("Mon event fonctionne un peu");
	}
}
