#include "Player.hpp"
#include <algorithm>

Player::Player(Pos player_pos) :
	Object{player_pos},
	weapon{false},
	treasure{false},
	health{2},
	maxHealth{2}
{
	draw = 'H';
}


Player::~Player()
{
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
	Pos from = pos;
	pos = to;

	movedEvent(this, from, to);
}


void Player::addWeapon()
{
	weapon = true;
}


bool Player::hasWeapon() const
{
	return weapon;
}


void Player::addTreasure()
{
	treasure = true;
}


bool Player::hasTreasure() const
{
	return treasure;
}


void Player::damage(int value)
{
	health -= value;

	if (health <= 0) {
		setAliveStatus(false);
	}
}


void Player::heal(int value)
{
	health = std::min(health + value, maxHealth);
}


void Player::kill()
{
	health = 0;
	setAliveStatus(false);
}
