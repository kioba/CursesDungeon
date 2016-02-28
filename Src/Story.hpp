#ifndef __STORY_HPP__
#define __STORY_HPP__

#include "Defines.hpp"
#include <string>
#include <vector>

enum FIELD {
	EMPTY	= 0,
	WALL	= 1
};

class Story
{
protected: /* variables */
	std::string name;
	Size size;
	std::vector<std::vector<FIELD>> level;

public: /* funcitons */
	Story(std::string, Size size);
	virtual ~Story();

	Size getSize() const;
	std::string getName() const;
};

#endif // __STORY_HPP__
