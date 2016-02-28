#include "Story.hpp"

Story::Story(std::string story_name, Size story_size) :
	name{story_name},
	size{story_size}
{
}


Story::~Story()
{
}


Size Story::getSize() const
{
	return size;
}


std::string Story::getName() const
{
	return name;
}
