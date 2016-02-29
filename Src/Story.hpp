#ifndef __STORY_HPP__
#define __STORY_HPP__

#include "Defines.hpp"
#include <string>
#include <vector>
#include <iostream>

enum FIELD {
	EMPTY	= 0,
	WALL	= 1
};

class Story
{
protected: /* variables */
	std::string name;
	Size size;
	Matrix<FIELD> level;

public: /* funcitons */
	Story(std::string, Size size);
	virtual ~Story();

	Size getSize() const;
	std::string getName() const;

	void printStory() const;
	Matrix<char> asStringMatrix() const;
	char convertToChar(FIELD field) const;

};

#endif // __STORY_HPP__
