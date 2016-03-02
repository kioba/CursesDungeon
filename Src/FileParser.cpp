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

		std::string name = "story ";
		name += std::to_string(i);
		name += ":";

		Story story(name, Size(size_x, size_y));

		in.getline(line, size_y);

		for (uint i = 0; i < size_x; ++i) {
			in.getline(line, value);
			for (uint j = 0; j < size_y; ++j) {
				FIELDTYPE type = getFieldfromSource(line[j]);
				createGameElement(type, Pos(i, j));


				if (line[j] == 'h' || line[j] == 'H') {
				} else if (line[j] == 'x' || line[j] == 'X') {
				}
			}
		}

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


void FileParser::createGameElement(char source)
{
	MAPTYPE field = EMPTY;
	switch (source) {
		case ' ':
		case 'x':
		case 'X':
			story.set(Pos(i, j), source);
			break;

		case 'h':
		case 'H':
			player = new Player(Pos(i, j));
			break;

		case 'a':
		case 'A':
			field = WEAPON;
			break;

		case 's':
		case 'S':
			field = MONSTER;
			break;

		case 'k':
		case 'K':
			field = TREASURE;
			break;

		case 'i':
		case 'I':
			field = POTION;
			break;

		case 'c':
		case 'C':
			field = TRAP;
			break;

		case 'j':
		case 'J':
			field = EXIT;
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
