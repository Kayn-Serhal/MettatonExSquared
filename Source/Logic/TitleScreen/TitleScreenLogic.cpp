#include "../../../Headers/Logic/TitleScreen/TitleScreenLogic.h"
#include "../../../Headers/GameLoader.h"

void TitleScreenLogic::handleEvent(const Uint8* keys)
{

	if (keys[SDL_SCANCODE_RETURN])
	{
		GameLoader::loadScene(GamePlayState::OVERWORLD);
	}
}
