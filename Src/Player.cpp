#include "Player.hpp"
#include <algorithm>

Player::Player(Pos player_pos) :
	Object{player_pos},
	weapon{false},
	treasure{false},
	autopilot{false},
	health{2},
	maxHealth{2}
{
	draw = 'H';
}


Player::~Player()
{
}


bool Player::move(Direction dir)
{
	bool result = true;
	if (autopilot) {
		autopilotMove();
	} else {
		result = playerMove(dir);
	}
	return result;
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


int Player::getHP() const
{
	return health;
}
int Player::getMaxHP() const
{
	return maxHealth;
}


void Player::setAutopilotStatus(bool state)
{
	autopilot = state;
}


bool Player::isAutopilot() const
{
	return autopilot;
}


void Player::autopilotMove()
{

}


bool Player::playerMove(Direction dir)
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
		return false;
	}

	Pos from = pos;
	pos = to;

	MoveEvent event;
	event.player = this;
	event.from = from;
	event.to = to;
	event.dir = dir;
	movedEvent(event);

	return true;
}
