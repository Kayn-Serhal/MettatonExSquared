#include "../../../Headers/GameComponents/Player/Player.h"


Player::Player()
{
	this->x = 200;
	this->y = 200;
	this->playerGraphic.x = x;
	this->playerGraphic.y = y;

}

Player::Player(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Player::moveUp()
{
	this->y -= VELOCITY;
	this->playerGraphic.y = y;
}

void Player::moveDown()
{
	this->y += VELOCITY;
	this->playerGraphic.y = y;
}

void Player::moveLeft()
{
	this->x -= VELOCITY;
	this->playerGraphic.x = x;
}

void Player::moveRight()
{
	this->x += VELOCITY;
	this->playerGraphic.x = x;
}

SDL_Rect Player::getHitbox()
{
	return this->playerGraphic.hitbox;
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}

void Player::setX(int newX)
{
	//this->previousX = this->x;
	this->x = this->playerGraphic.x = this->playerGraphic.hitbox.x = newX;
}

void Player::setY(int newY)
{
	//->previousX = this->x;
	this->y = this->playerGraphic.y = this->playerGraphic.hitbox.y= newY;
}

int Player::getPreviousX()
{
	// previousX;
	return 0;
}

int Player::getPreviousY()
{
	// previousY;
	return 0;
}




