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


void Player::move(Direction dir)
{
	Pos to = pos;
	switch (dir) {
		case UP:
			to.first -= 1;
			break;

		case DOWN:
			to.first += 1;
			break;

		case LEFT:
			to.second -= 1;
			break;

		case RIGHT:
			to.second += 1;
			break;
	}

	if(!checkMovable(pos, to)) {
		return;
	}

	pos = to;
}
