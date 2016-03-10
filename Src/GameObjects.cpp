#include "GameObjects.hpp"

Weapon::Weapon(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'a';
}


Weapon::~Weapon()
{
}


void Weapon::moved(MoveEvent& event)
{
	if (pos == event.to) {
		event.player->addWeapon();
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


void Monster::moved(MoveEvent& event)
{
	if (!isInRadius(event.to, 0) || !isAlive()) {
		return;
	}

	if (event.player->hasWeapon()) {
		setAliveStatus(false);
		event.player->damage(1);
	} else {
		event.player->kill();
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


void Treasure::moved(MoveEvent& event)
{
	if (pos == event.to) {
		event.player->addTreasure();
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


void Potion::moved(MoveEvent& event)
{
	if (pos == event.to) {
		event.player->heal(1);
		setAliveStatus(false);
	}
}


Trap::Trap(Pos obj_pos) :
	Object(obj_pos),
	isTriggered{false}
{
	draw = 'c';
}


Trap::~Trap()
{
}


bool Trap::couldMove(const Pos& from, const Pos& to)
{
	if (isTriggered && pos == to) {
		return false;
	}

	return true;
}


void Trap::moved(MoveEvent& event)
{
	if (pos != event.to) {
		return;
	}

	if(event.player->move(event.dir)) {
		draw = 'x';
		isTriggered = true;
	}
}


Exit::Exit(Pos obj_pos) :
	Object(obj_pos)
{
	draw = 'j';
}


Exit::~Exit()
{
}


void Exit::moved(MoveEvent& event)
{
	(void) event;
}
