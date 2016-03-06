#include "FileParser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include "Defines.hpp"

FileParser::FileParser(std::string path) :
	major_version{0},
	minor_version{0},
	patch_version{0},
	story{new Story("", Size(0, 0))},
	map{new Map()},
	player{new Player{Pos(-1, -1)}}
{
	std::ifstream in(path, std::ifstream::in);

	if(in.is_open()) {
		uint stories = 0;
		uint size_x = 0;
		uint size_y = 0;

		in >> major_version;
		in >> minor_version;
		in >> patch_version;
		in >> size_x;
		in >> size_y;

		const int value = size_y + 10;
		char* line = new char[value];

		std::string name = "story one";
		story.reset(new Story(name, Size(size_x, size_y)));

		in.getline(line, size_y);

		for (uint i = 0; i < size_x; ++i) {
			in.getline(line, value);
			for (uint j = 0; j < size_y; ++j) {
				createGameElement(line[j], Pos(i, j));
			}
		}

		map->appendStory(*story);

		delete[] line;

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


void FileParser::createGameElement(char source, Pos pos)
{
	switch (source) {
		case ' ':
		case 'x':
		case 'X':
			story->set(pos, source);
			break;

		case 'h':
		case 'H':
			player.reset(new Player(pos));
			break;

		case 'a':
		case 'A':
			// WEAPON
			break;

		case 's':
		case 'S':
			// MONSTER
			break;

		case 'k':
		case 'K':
			// TREASURE
			break;

		case 'i':
		case 'I':
			// POTION
			break;

		case 'c':
		case 'C':
			// TRAP
			break;

		case 'j':
		case 'J':
			// EXIT
			break;

		default:
			break;
	}
}

const Map FileParser::getMap() const
{
	return *map;
}


const Player FileParser::getPlayer() const
{
	return *player;
}
