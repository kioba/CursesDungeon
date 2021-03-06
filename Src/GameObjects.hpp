#ifndef __GAMEOBJECTS_HPP__
#define __GAMEOBJECTS_HPP__

#include "EventSources.hpp"
#include "Defines.hpp"
#include "Player.hpp"
#include "Object.hpp"


class Weapon :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Weapon(Pos obj_pos);
	virtual ~Weapon();

	virtual void moved(MoveEvent& event) override;
};


class Monster :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Monster(Pos obj_pos);
	virtual ~Monster();

	virtual bool couldMove(const Pos& from, const Pos& to) override;
	virtual bool isDanger(const Pos& from, const Pos& to) override;
	virtual void moved(MoveEvent& event) override;
};


class Treasure :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Treasure(Pos obj_pos);
	virtual ~Treasure();

	virtual void moved(MoveEvent& event) override;
};


class Potion :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Potion(Pos obj_pos);
	virtual ~Potion();

	virtual void moved(MoveEvent& event) override;
};


class Trap :
	public Object,
	public PlayerMoveEventHandler
{
private: /* variables */
	bool isTriggered;

public: /* functions */
	Trap(Pos obj_pos);
	virtual ~Trap();

	virtual bool couldMove(const Pos& from, const Pos& to) override;
	virtual void moved(MoveEvent& event) override;
};


class Exit :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Exit(Pos obj_pos);
	virtual ~Exit();

	virtual void moved(MoveEvent& event) override;
};

#endif // __GAMEOBJECTS_HPP__
