#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Defines.hpp"
#include "EventSources.hpp"
#include "Object.hpp"

class Player :
	public Object,
	public PlayerMoveEventSource
{
private: /* variables */
	bool weapon;
	bool treasure;
	bool autopilot;
	int health;
	int maxHealth;

private: /* functions */
	void autopilotMove();
	bool playerMove(Direction dir);

public: /* functions */
	Player(Pos player_pos);
	virtual ~Player();

	bool move(Direction dir);

	void addWeapon();
	bool hasWeapon() const;

	void addTreasure();
	bool hasTreasure() const;

	void damage(int value);
	void heal(int value);
	void kill();

	int getHP() const;
	int getMaxHP() const;

	void setAutopilotStatus(bool state);
	bool isAutopilot() const;
};

#endif // __PLAYER_HPP__
