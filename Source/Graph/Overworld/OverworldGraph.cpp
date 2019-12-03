#include "../../../Headers/Graph/Overworld/OverworldGraph.h"
#include "../../../Headers/Components/MetGraphicalStaticObject.h"
void OverworldGraph::load() {
	this->backGroundTexture.loadFromFile("bgBide.png", this->renderer);
	this->spriteTexture.loadFromFile("spriBide.png", this->renderer, 0xFF, 0xFF, 0xFF);
}

void OverworldGraph::update() {
	this->backGroundTexture.render(0, 0, NULL, this->renderer);
	this->player->currentSpriteSheetTexture()->render(x, y, this->player->methodeTest(this->player->currentFrame/4), this->renderer);
	MetGraphicalStaticObject ron(120, 120);
	ron.loadSpriteFromFilename("ble.png");
	ron.render();
}