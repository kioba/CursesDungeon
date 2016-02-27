#ifndef __FILEPARSER_HPP__
#define __FILEPARSER_HPP__

#include <string>
#include <vector>

class FileParser
{
private: /* variables */
	std::vector<std::string> vec;

public: /* function */
	FileParser(std::string path);
	virtual ~FileParser();

	void print() const;
};

#endif // __FILEPARSER_HPP__
