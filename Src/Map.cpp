#include "Map.hpp"

Map::Map()
{
}


Map::~Map()
{
}


uint Map::getStorysNumber() const
{
	return static_cast<uint>(dungeon.size());
}


Size Map::getStorySize(const std::string& story_name) const
{
	auto story = dungeon.find(story_name);
	if (story != dungeon.end()) {
		return story->second.getSize();
	}

	return Size(0, 0);
}


void Map::appendStory(Story& story)
{
	std::pair<std::string, Story> insert(story.getName(), story);
	dungeon.insert(insert);
}


void Map::printMap() const
{
	for (const auto& story : dungeon) {
		story.second.printStory();
	}
}


Matrix<char> Map::getStoryMatrix(std::string story_name)
{
	auto story = dungeon.find(story_name);
	if (story != dungeon.end()) {
		return story->second.asMatrix();
	}
	return Matrix<char> ();
}

bool Map::couldMove(const Pos& from, const Pos& to) const
{
	auto story = dungeon.find("story 0:");
	if (story != dungeon.end()) {
		Size size = story->second.getSize();

		if (size.first <= to.first || 0 > to.first ||
			size.second <= to.second || 0 > to.second)
		{
			return false;
		}

		if (story->second.getPosValue(to) == 'x') {
			return false;
		}
	}

	return true;
}
