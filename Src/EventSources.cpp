#include "EventSources.hpp"

MovableEventHandler::MovableEventHandler()
{
}


MovableEventHandler::~MovableEventHandler()
{
	for(auto& source : sources) {
		if (source != nullptr) {
			source->detach(this);
		}
	}
}


bool MovableEventHandler::couldMove(const Pos& from, const Pos& to) const
{
	(void) from;
	(void) to;

	return true;
}

void MovableEventHandler::removeSource(MovableEventSource* source)
{
	if (source == nullptr) {
		return;
	}

	auto search = std::find(sources.begin(), sources.end(), source);

	if (search != sources.end()) {
		sources.erase(search);
	}
}


MovableEventSource::MovableEventSource()
{
}


MovableEventSource::~MovableEventSource()
{
	for(auto& handler : handlers) {
		if (handler != nullptr) {
			handler->removeSource(this);
		}
	}
}


void MovableEventSource::attach(MovableEventHandler* handler)
{
	auto search = std::find(handlers.begin(), handlers.end(), handler);

	if (handler != nullptr && search == handlers.end()) {
		handlers.push_back(handler);
	}
}


void MovableEventSource::detach(MovableEventHandler* handler)
{
	if (handler == nullptr) {
		return;
	}

	auto search = std::find(handlers.begin(), handlers.end(), handler);

	if (search != handlers.end()) {
		handlers.erase(search);
	}
}


bool MovableEventSource::checkMovable(const Pos& from, const Pos& to) const
{
	for (auto& handler : handlers) {
		if (handler != nullptr) {
			if (!handler->couldMove(from, to)) {
				return false;
			}
		}
	}

	return true;
}
