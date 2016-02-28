#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "Story.hpp"
#include "Defines.hpp"
#include <map>
#include <string>

class Map
{
protected: /* variables */
	std::map<std::string, Story> dungeon;

public: /* functions */
	Map();
	virtual ~Map();

	inline uint getStorysNumber() const;
	inline Size getStorySize(const std::string& story_name) const;
	void appendStory(Story& story);

	void printMap() const;
};

#endif // __MAP_HPP__
