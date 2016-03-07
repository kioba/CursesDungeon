#include "GameObjects.hpp"

Weapon::Weapon(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'a';
}


Weapon::~Weapon()
{
}


void Weapon::moved(const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;
}


bool Monster::couldMove(const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;

	return true;
}


Monster::Monster(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 's';
}


Monster::~Monster()
{
}


void Monster::moved(const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;
}


Treasure::Treasure(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'k';
}


Treasure::~Treasure()
{
}


void Treasure::moved(const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;
}


Potion::Potion(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'i';
}


Potion::~Potion()
{
}


void Potion::moved(const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;
}


Trap::Trap(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'c';
}


Trap::~Trap()
{
}


void Trap::moved(const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;
}


Exit::Exit(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'j';
}


Exit::~Exit()
{
}


void Exit::moved(const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;
}
