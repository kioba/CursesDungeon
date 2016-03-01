#ifndef __ENVENTSOURCE_HPP__
#define __ENVENTSOURCE_HPP__

#include <vector>
#include "Defines.hpp"

class MovableEventSource;
class MovableEventHandler;

class MovableEventHandler
{
private: /* variables */
	std::vector<MovableEventSource*> sources;

public: /* functions */
	MovableEventHandler();
	virtual ~MovableEventHandler();

	void removeSource(MovableEventSource* source);

	virtual bool couldMove(const Pos& from, const Pos& to) const;
};


class MovableEventSource
{
private: /* variables */
	std::vector<MovableEventHandler*> handlers;

public: /* functions */
	MovableEventSource();
	virtual ~MovableEventSource();

	void attach(MovableEventHandler* handler);
	void detach(MovableEventHandler* handler);

	bool checkMovable(const Pos& from, const Pos& to) const;
};


#endif // __ENVENTSOURCE_HPP__
