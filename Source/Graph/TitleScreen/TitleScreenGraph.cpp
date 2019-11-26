#include "../../../Headers/Graph/TitleScreen/TitleScreenGraph.h"




void TitleScreenGraph::load() {

	this->titleScreenTexture.loadFromFile("title.png",this->renderer);
}

void TitleScreenGraph::render() {
	this->titleScreenTexture.render(0, 0, NULL, this->renderer);
	
}