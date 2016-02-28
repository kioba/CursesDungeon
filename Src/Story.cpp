#include "Story.hpp"

Story::Story(std::string story_name, Size story_size) :
	name{story_name},
	size{story_size},
	level{story_size.first, std::vector<FIELD>(story_size.second, FIELD::EMPTY)}
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


void Story::printStory() const
{
	std::cout << name << std::endl;

	if (level.size() == 0) {
		return;
	}

	std::string str(level[0].size() * 2 + 2, '-');
	std::cout << str << std::endl;

	for (size_t i = 0; i < level.size(); ++i) {
		std::cout << '|';
		for (size_t j = 0; j < level[i].size(); ++j) {
			std::cout << convertToChar(level[i][j]) << " ";
		}
		std::cout << '|' << std::endl;
	}

	std::cout << str << std::endl;
}

char Story::convertToChar(FIELD field) const
{
	char ret = '+';
	switch (field) {
		case EMPTY:
			ret = ' ';
			break;
		default:
			break;
	}
	return ret;
}
