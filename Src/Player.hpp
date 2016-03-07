#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Defines.hpp"
#include "EventSources.hpp"
#include "Object.hpp"

class Player :
	public Object,
	public PlayerMoveEventSource
{
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
};

#endif // __PLAYER_HPP__
