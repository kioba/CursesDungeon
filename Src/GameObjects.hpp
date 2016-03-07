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

	virtual void moved(Player* source, const Pos& from, const Pos& to) override;
};


class Monster :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Monster(Pos obj_pos);
	virtual ~Monster();

	virtual bool couldMove(const Pos& from, const Pos& to) override;
	virtual void moved(Player* source, const Pos& from, const Pos& to) override;
};


class Treasure :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Treasure(Pos obj_pos);
	virtual ~Treasure();

	virtual void moved(Player* source, const Pos& from, const Pos& to) override;
};


class Potion :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Potion(Pos obj_pos);
	virtual ~Potion();

	virtual void moved(Player* source, const Pos& from, const Pos& to) override;
};


class Trap :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Trap(Pos obj_pos);
	virtual ~Trap();

	virtual void moved(Player* source, const Pos& from, const Pos& to) override;
};


class Exit :
	public Object,
	public PlayerMoveEventHandler
{
public: /* functions */
	Exit(Pos obj_pos);
	virtual ~Exit();

	virtual void moved(Player* source, const Pos& from, const Pos& to) override;
};

#endif // __GAMEOBJECTS_HPP__
