#include "Story.hpp"

Story::Story(std::string story_name, Size story_size) :
	name{story_name},
	size{story_size},
	level{story_size.first, std::vector<char>(story_size.second, ' ')}
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


void Story::set(Pos pos, char type)
{
	level[pos.first][pos.second] = type;
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
			std::cout << level[i][j] << " ";
		}
		std::cout << '|' << std::endl;
	}

	std::cout << str << std::endl;
}


Matrix<char> Story::asMatrix() const
{
	return level;
}
