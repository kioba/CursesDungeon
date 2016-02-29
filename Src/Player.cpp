#include "Player.hpp"

Player::Player(Pos player_pos) :
	pos{player_pos}
{
}


Player::~Player()
{
}


int Player::getX() const
{
	return pos.first;
}


int Player::getY() const
{
	return pos.second;
}
