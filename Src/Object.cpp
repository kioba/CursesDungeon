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
