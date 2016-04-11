#ifndef __ENVENTSOURCE_HPP__
#define __ENVENTSOURCE_HPP__

#include <vector>
#include "Defines.hpp"

class Player;
enum Direction;
class PlayerMoveEventSource;
class MoveEvent;
class PlayerMoveEventHandler;

class PlayerMoveEventHandler
{
private: /* variables */
	std::vector<PlayerMoveEventSource*> sources;

public: /* functions */
	PlayerMoveEventHandler();
	virtual ~PlayerMoveEventHandler();

	void removeSource(PlayerMoveEventSource* source);

	virtual bool couldMove(const Pos& from, const Pos& to);
	virtual bool isDanger(const Pos& from, const Pos& to);
	virtual void moved(MoveEvent& event);
};


class PlayerMoveEventSource
{
private: /* variables */
	std::vector<PlayerMoveEventHandler*> handlers;

public: /* functions */
	PlayerMoveEventSource();
	virtual ~PlayerMoveEventSource();

	void attach(PlayerMoveEventHandler* handler);
	void detach(PlayerMoveEventHandler* handler);

	bool checkMovable(const Pos& from, const Pos& to) const;
	bool checkDanger(const Pos& from, const Pos& to) const;
	
	void movedEvent(MoveEvent& event) const;
};

class MoveEvent
{
public:
	Player* player;
	Pos from;
	Pos to;
	Direction dir;

	MoveEvent() :
		player{nullptr}
	{}

	virtual ~MoveEvent()
	{}
};

#endif // __ENVENTSOURCE_HPP__
