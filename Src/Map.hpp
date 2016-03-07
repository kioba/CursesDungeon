#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "Story.hpp"
#include "Defines.hpp"
#include "EventSources.hpp"
#include <map>
#include <string>

class Map :
	public PlayerMoveEventHandler
{
protected: /* variables */
	Story dungeon;

public: /* functions */
	Map();
	virtual ~Map();

	inline uint getStorysNumber() const;
	inline Size getStorySize() const;
	void appendStory(const Story& story);
	Matrix<char> getStoryMatrix();

	void printMap() const;

	virtual bool couldMove(const Pos& from, const Pos& to) override;

};

#endif // __MAP_HPP__
