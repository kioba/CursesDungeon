#include "Map.hpp"

Map::Map() :
	dungeon{"", Size(0, 0)}
{
}


Map::~Map()
{
}


uint Map::getStorysNumber() const
{
	return 1;
}


Size Map::getStorySize(const std::string& story_name) const
{
	return dungeon.getSize();
}


void Map::appendStory(const Story& story)
{
	dungeon = story;
}


void Map::printMap() const
{
	dungeon.printStory();
}


Matrix<char> Map::getStoryMatrix(std::string story_name)
{
	return dungeon.asMatrix();
}

bool Map::couldMove(const Pos& from, const Pos& to) const
{
	Size size = dungeon.getSize();

	if (size.first <= to.first || 0 > to.first ||
		size.second <= to.second || 0 > to.second)
	{
		return false;
	}

	if (dungeon.getPosValue(to) == 'x') {
		return false;
	}

	return true;
}
