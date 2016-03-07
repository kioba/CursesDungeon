#include "Object.hpp"

Object::Object(Pos obj_pos) :
	pos{obj_pos},
	alive{true},
	draw{' '}
{

}


Object::~Object()
{

}


bool Object::isAlive() const
{
	return alive;
}


void Object::setAliveStatus(bool status)
{
	alive = status;
}


int Object::getX() const
{
	return pos.first;
}


int Object::getY() const
{
	return pos.second;
}

char Object::getDraw() const
{
	return draw;
}


bool Object::isInRadius(Pos rad_pos, int radius) const
{
	bool horizontal = (pos.first + radius) >= rad_pos.first &&
	 					(pos.first - radius) <= rad_pos.first;
	bool vertical = (pos.second + radius) >= rad_pos.second &&
	 					(pos.second - radius) <= rad_pos.second;

	return horizontal && vertical;
}
