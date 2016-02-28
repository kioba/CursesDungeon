#include "FileParser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include "Defines.hpp"

FileParser::FileParser(std::string path) :
	major_version{0},
	minor_version{0},
	patch_version{0}
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
			std::string name = "story one";
			name += std::to_string(i);
			Story story(name, Size(size_x, size_y));

			// TODO: SetMap
			// for (size_t i = 0; i < size_x; ++i) {
			// 	for (size_t j = 0; j < size_y; ++j) {
			//
			// 	}
			// }

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
