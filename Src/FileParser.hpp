#ifndef __FILEPARSER_HPP__
#define __FILEPARSER_HPP__

#include <string>
#include <vector>
#include "Defines.hpp"
#include "Map.hpp"
#include "Story.hpp"

class FileParser
{
private: /* variables */
	std::vector<std::string> vec;

	uint major_version;
	uint minor_version;
	uint patch_version;

	Map map;
public: /* function */
	FileParser(std::string path);
	virtual ~FileParser();

	void print() const;

	inline uint getMapMajorVersion() const;
	inline uint getMapMinorVersion() const;
	inline uint getMapPatchVersion() const;
	inline std::string getMapVersionString() const;

	Map getMap() const;
};

#endif // __FILEPARSER_HPP__
