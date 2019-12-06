#include "../../../Headers/Graph/Overworld/OverworldGraph.h"
#include "../../../Headers/CoreComponents/MTT_GraphicalStaticObject.h"
void OverworldGraph::load() {
	this->backGroundTexture.loadFromFile("bgBide.png", this->renderer);
}

void OverworldGraph::update() {
	SDL_RenderClear(Graphics::graphicHandler.gameRenderer);
	this->backGroundTexture.render(0, 0, NULL, this->renderer);
	this->player->playerGraphic.render();
}