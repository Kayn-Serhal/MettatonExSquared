#include "../../Headers/GameComponents/Player/Player.h"


Player::Player()
{
	this->x = 0;
	this->y = 0;
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



