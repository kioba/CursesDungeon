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
	int health;
	int maxHealth;

public: /* types */
	enum Direction {
		UP		= 0,
		DOWN	= 1,
		LEFT	= 2,
		RIGHT	= 3
	};

public: /* functions */
	Player(Pos player_pos);
	virtual ~Player();

	void move(Direction dir);

	void addWeapon();
	bool hasWeapon() const;

	void addTreasure();
	bool hasTreasure() const;

	void damage(int value);
	void heal(int value);
	void kill();
};

#endif // __PLAYER_HPP__
