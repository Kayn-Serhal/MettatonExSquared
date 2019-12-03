#include "../../../Headers/Graph/Overworld/OverworldGraph.h"
#include "../../../Headers/CoreComponents/MTT_GraphicalStaticObject.h"
void OverworldGraph::load() {
	this->backGroundTexture.loadFromFile("bgBide.png", this->renderer);
}

void OverworldGraph::update() {
	this->backGroundTexture.render(0, 0, NULL, this->renderer);
	//this->player->currentSpriteSheetTexture()->render(x, y, this->player->methodeTest(this->player->currentFrame/4), this->renderer);
}