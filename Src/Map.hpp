#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "Story.hpp"
#include "Defines.hpp"
#include "EventSources.hpp"
#include <map>
#include <string>

class Map :
	public MovableEventHandler
{
protected: /* variables */
	Story dungeon;

public: /* functions */
	Map();
	virtual ~Map();

	inline uint getStorysNumber() const;
	inline Size getStorySize(const std::string& story_name) const;
	void appendStory(const Story& story);
	Matrix<char> getStoryMatrix(std::string story_name);

	void printMap() const;

	bool couldMove(const Pos& from, const Pos& to) const override;

};

#endif // __MAP_HPP__
