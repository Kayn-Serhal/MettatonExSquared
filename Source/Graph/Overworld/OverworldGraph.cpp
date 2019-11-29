#include "../../../Headers/Graph/Overworld/OverworldGraph.h"

void OverworldGraph::load() {
	this->backGroundTexture.loadFromFile("bgBide.png", this->renderer);
	this->spriteTexture.loadFromFile("spriBide.png", this->renderer, 0xFF, 0xFF, 0xFF);
}

void OverworldGraph::update() {
	this->backGroundTexture.render(0, 0, NULL, this->renderer);
	this->player->currentSpriteSheetTexture()->render(x, y, this->player->methodeTest(0), this->renderer);

}