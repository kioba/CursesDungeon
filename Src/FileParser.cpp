#include "FileParser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include "Defines.hpp"

FileParser::FileParser(std::string path) :
	major_version{0},
	minor_version{0},
	patch_version{0},
	player{Pos(-1, -1)}
{
	std::ifstream in(path, std::ifstream::in);

	if(in.is_open()) {
		uint stories;

		in >> major_version;
		in >> minor_version;
		in >> patch_version;
		in >> stories;

		uint size_x;
		uint size_y;
		for (size_t i = 0; i < stories; ++i) {
			in >> size_x;
			in >> size_y;
			char line[size_y + 10];
			std::string name = "story ";
			name += std::to_string(i);
			name += ":";
			Story story(name, Size(size_x, size_y));

			in.getline(line, size_y);
			// TODO: SetMap
			for (size_t i = 0; i < size_x; ++i) {
				in.getline(line, size_y + 10);
				for (size_t j = 0; j < size_y; ++j) {
					if (line[j] == 'h' || line[j] == 'H') {
						player = Player(Pos(i, j));
						std::cout << i << " " << j << std::endl;
					} else if (line[j] == 'x' || line[j] == 'X') {
						story.set(Pos(i, j), line[j]);
					}
				}
			}

			map.appendStory(story);
		}

		in.close();
	} else {
		std::cerr << "Could not open file: " << path << std::endl;
	}
}


FileParser::~FileParser()
{

}


void FileParser::print() const
{
	std::cout << getMapVersionString() << std::endl;
}


uint FileParser::getMapMajorVersion() const
{
	return major_version;
}


uint FileParser::getMapMinorVersion() const
{
	return minor_version;
}


uint FileParser::getMapPatchVersion() const
{
	return patch_version;
}


std::string FileParser::getMapVersionString() const
{
	std::stringstream ss;
	ss << "Version: ";
	ss << major_version << ".";
	ss << minor_version << ".";
	ss << patch_version;
	return ss.str();
}


FileParser::MAPTYPE FileParser::getFieldfromSource(char source) const
{
	MAPTYPE field = EMPTY;
	switch (source) {
		case 'h':
		case 'H':
			field = HERO;
			break;
		default:
			break;
	}

	return field;
}


const Map& FileParser::getMap() const
{
	return map;
}


const Player& FileParser::getPlayer() const
{
	return player;
}
