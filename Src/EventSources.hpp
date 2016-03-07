#ifndef __ENVENTSOURCE_HPP__
#define __ENVENTSOURCE_HPP__

#include <vector>
#include "Defines.hpp"

class Player;
class PlayerMoveEventSource;
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
	virtual void moved(Player* source, const Pos& from, const Pos& to);
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
	void movedEvent(Player* source, const Pos& from, const Pos& to) const;
};


#endif // __ENVENTSOURCE_HPP__
