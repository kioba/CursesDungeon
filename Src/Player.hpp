#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Defines.hpp"
#include "EventSources.hpp"

class Player :
	public MovableEventSource
{
protected: /* variables */
	Pos pos;

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

	int getX() const;
	int getY() const;

	void move(Direction dir);
};

#endif // __PLAYER_HPP__
