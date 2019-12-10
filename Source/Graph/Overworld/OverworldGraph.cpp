#include "../../../Headers/Graph/Overworld/OverworldGraph.h"
#include "../../../Headers/CoreComponents/MTT_GraphicalStaticObject.h"
void OverworldGraph::load() {
	this->backGroundTexture.loadFromFile("bgBide2.png", this->renderer);
	this->camera.x = this->camera.y = 0;
	this->camera.h = 480;
	this->camera.w = 640;

}

void OverworldGraph::free()
{
	this->backGroundTexture.free();
	
}

void OverworldGraph::checkIfPlayerIsTryingToGoOutOfBoundsBecauseHeIsProllyADumbass()
{
	if (this->player->x<0) 
		this->player->x += this->player->VELOCITY;
	if (this->player->y<0)
		this->player->y += this->player->VELOCITY;
	if (this->player->y + this->player->playerGraphic.getSpriteHeight() > LEVELHEIGHT)
		this->player->y -= this->player->VELOCITY;
	if (this->player->x + this->player->playerGraphic.getSpriteWidth() > LEVELWIDTH)
		this->player->x -= this->player->VELOCITY;
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

	camera.x = (this->player->x + this->player->playerGraphic.getSpriteWidth() / 2) - 640 / 2;
	camera.y = (this->player->y + this->player->playerGraphic.getSpriteHeight() / 2) - 480 / 2;
	this->checkIfPlayerIsTryingToGoOutOfBoundsBecauseHeIsProllyADumbass();
	this->checkIfCameraIsTryingToGoOutOfBounds();
	this->backGroundTexture.render(0, 0, ((SDL_Rect*)&camera), this->renderer);
	this->player->playerGraphic.render(camera);
}
