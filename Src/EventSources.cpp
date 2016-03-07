#include "EventSources.hpp"

PlayerMoveEventHandler::PlayerMoveEventHandler()
{
}


PlayerMoveEventHandler::~PlayerMoveEventHandler()
{
	for(auto& source : sources) {
		if (source != nullptr) {
			source->detach(this);
		}
	}
}


bool PlayerMoveEventHandler::couldMove(const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;

	return true;
}


void PlayerMoveEventHandler::moved(Player* source, const Pos& from, const Pos& to)
{
	(void) from;
	(void) to;
	(void) source;
}


void PlayerMoveEventHandler::removeSource(PlayerMoveEventSource* source)
{
	if (sources.size() == 0 || source == nullptr) {
		return;
	}

	auto search = std::find(sources.begin(), sources.end(), source);

	if (search != sources.end()) {
		sources.erase(search);
	}
}


PlayerMoveEventSource::PlayerMoveEventSource()
{
}


PlayerMoveEventSource::~PlayerMoveEventSource()
{
	for(auto& handler : handlers) {
		if (handler != nullptr) {
			handler->removeSource(this);
		}
	}
}


void PlayerMoveEventSource::attach(PlayerMoveEventHandler* handler)
{
	auto search = std::find(handlers.begin(), handlers.end(), handler);

	if (handler != nullptr && search == handlers.end()) {
		handlers.push_back(handler);
	}
}


void PlayerMoveEventSource::detach(PlayerMoveEventHandler* handler)
{
	if (handler == nullptr) {
		return;
	}

	auto search = std::find(handlers.begin(), handlers.end(), handler);

	if (search != handlers.end()) {
		handlers.erase(search);
	}
}


bool PlayerMoveEventSource::checkMovable(const Pos& from, const Pos& to) const
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



void PlayerMoveEventSource::movedEvent(Player* source, const Pos& from, const Pos& to) const
{
	if (source == nullptr) {
		return;
	}

	for (auto& handler : handlers) {
		if (handler != nullptr) {
			handler->moved(source, from, to);
		}
	}
}
