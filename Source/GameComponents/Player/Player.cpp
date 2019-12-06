#include "../../../Headers/GameComponents/Player/Player.h"


Player::Player()
{
	this->x = 200;
	this->y = 200;
	this->playerGraphic.x = &x;
	this->playerGraphic.y = &y;

}

Player::Player(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Player::moveUp()
{
	this->y -= VELOCITY;
}

void Player::moveDown()
{
	this->y += VELOCITY;
}

void Player::moveLeft()
{
	this->x -= VELOCITY;
}

void Player::moveRight()
{
	this->x += VELOCITY;
}




