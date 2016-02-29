#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Defines.hpp"

class Player
{
protected: /* variables */
	Pos pos;

public: /* functions */
	Player(Pos player_pos);
	virtual ~Player();

	int getX() const;
	int getY() const;
};

#endif // __PLAYER_HPP__
