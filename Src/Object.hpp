#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include "Defines.hpp"

class Object {
protected: /* variables */
	Pos pos;
	bool alive;
	char draw;

public:
	Object(Pos obj_pos);
	virtual ~Object();

	bool isAlive() const;
	void setAliveStatus(bool status);

	int getX() const;
	int getY() const;

	char getDraw() const;

	bool isInRadius(Pos pos, int radius) const;
};


#endif // __OBJECT_HPP__
