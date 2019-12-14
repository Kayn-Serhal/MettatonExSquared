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




