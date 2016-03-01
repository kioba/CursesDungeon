#ifndef __STORY_HPP__
#define __STORY_HPP__

#include "Defines.hpp"
#include <string>
#include <vector>
#include <iostream>

class Story
{
protected: /* variables */
	std::string name;
	Size size;
	Matrix<char> level;

public: /* funcitons */
	Story(std::string story_name, Size size);
	virtual ~Story();

	Size getSize() const;
	std::string getName() const;
	void set(Pos pos, char type);

	void printStory() const;
	Matrix<char> asMatrix() const;
	char getPosValue(Pos pos) const;
};

#endif // __STORY_HPP__
