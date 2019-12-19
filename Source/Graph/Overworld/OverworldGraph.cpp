#include "../../../Headers/Graph/Overworld/OverworldGraph.h"
#include "../../../Headers/CoreComponents/MTT_GraphicalStaticObject.h"
#include <iostream>
void OverworldGraph::load() {
	this->backGroundTexture.loadFromFile(this->pathAssets+"\\"+BACKGROUND_FILE, this->renderer);
	this->camera.x = this->camera.y = 0;
	this->camera.h = 480;
	this->camera.w = 640;
	std::cout << this->pathAssets + "\\" + BACKGROUND_FILE << std::endl;

}

void OverworldGraph::free()
{
	this->backGroundTexture.free();
	
}

void OverworldGraph::checkIfPlayerIsTryingToGoOutOfBoundsBecauseHeIsProllyADumbass()
{
	if (this->player->getX() <0)
		this->player->setX(this->player->getX() + this->player->VELOCITY);
	if (this->player->getY() <0)
		this->player->setY(this->player->getY() + this->player->VELOCITY);
	if (this->player->getY() + this->player->playerGraphic.getSpriteHeight() > LEVELHEIGHT)
		this->player->setY(this->player->getY() - this->player->VELOCITY);
	if (this->player->getX() + this->player->playerGraphic.getSpriteWidth() > LEVELWIDTH)
		this->player->setX(this->player->getX()- this->player->VELOCITY);
}

void OverworldGraph::checkIfCameraIsTryingToGoOutOfBounds()
{
	if (camera.x < 0)
	{
		camera.x = 0;
	}
	if (camera.y < 0)
	{
		camera.y = 0;
	}
	if (camera.x > LEVELWIDTH - camera.w)
	{
		camera.x = LEVELWIDTH - camera.w;
	}
	if (camera.y > LEVELHEIGHT - camera.h)
	{
		camera.y = LEVELHEIGHT - camera.h;
	}
}

void OverworldGraph::update() {
	SDL_RenderClear(Graphics::graphicHandler.gameRenderer);

	//Camera focus on player at all times
	camera.x = (this->player->getX() + this->player->playerGraphic.getSpriteWidth() / 2) - 640 / 2;
	camera.y = (this->player->getY() + this->player->playerGraphic.getSpriteHeight() / 2) - 480 / 2;
	this->checkIfPlayerIsTryingToGoOutOfBoundsBecauseHeIsProllyADumbass();
	this->checkIfCameraIsTryingToGoOutOfBounds();
	this->backGroundTexture.render(0, 0, ((SDL_Rect*)&camera), this->renderer);
	this->player->playerGraphic.render(camera);
	for (const auto& asset : this->areaAssets)
	{
		asset->render(this->camera);
	}

}
