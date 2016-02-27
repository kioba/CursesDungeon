#include "FileParser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

FileParser::FileParser(std::string path)
{
	std::ifstream in(path, std::ifstream::in);
	std::stringstream ss;

	while(!in.eof() && in.good() && in.is_open()) {
		char a = in.get();
		ss << a;
	}

	vec.push_back(ss.str());
	in.close();
}


FileParser::~FileParser()
{

}

void FileParser::print() const
{
	if (vec.size() != 0) {
		std::cout << vec[0] << std::endl;
	}

}
