#include "GameObjects.hpp"

Weapon::Weapon(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'a';
}


Weapon::~Weapon()
{
}


void Weapon::moved(Player* source, const Pos& from, const Pos& to)
{
	(void) from;
	if (pos == to) {
		source->addWeapon();
		setAliveStatus(false);
	}
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


void Monster::moved(Player* source, const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;

	if (!isInRadius(to, 1) || !isAlive()) {
		return;
	}

	if (source->hasWeapon()) {
		setAliveStatus(false);
		source->damage(1);
	} else {
		source->kill();
	}
}


Treasure::Treasure(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'k';
}


Treasure::~Treasure()
{
}


void Treasure::moved(Player* source, const Pos& from, const Pos& to)
{
	(void)from;
	if (pos == to) {
		source->addTreasure();
		setAliveStatus(false);
	}
}


Potion::Potion(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'i';
}


Potion::~Potion()
{
}


void Potion::moved(Player* source, const Pos& from, const Pos& to)
{
	(void)from;
	if (pos == to) {
		source->heal(1);
		setAliveStatus(false);
	}
}


Trap::Trap(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'c';
}


Trap::~Trap()
{
}


void Trap::moved(Player* source, const Pos& from, const Pos& to)
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


void Exit::moved(Player* source, const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;
	(void)source;
}
