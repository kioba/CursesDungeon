#ifndef __FILEPARSER_HPP__
#define __FILEPARSER_HPP__

#include <string>
#include <vector>
#include "Defines.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Story.hpp"

class FileParser
{
private: /* variables */
	std::vector<std::string> vec;

	uint major_version;
	uint minor_version;
	uint patch_version;

	Map map;
	Player player;

	enum MAPTYPE {
		EMPTY	= 0,
		WALL	= 1,
		HERO	= 2,
		MONSTER	= 3
	};

	MAPTYPE getFieldfromSource(char source) const;

public: /* function */

	FileParser(std::string path);
	virtual ~FileParser();

	void print() const;

	inline uint getMapMajorVersion() const;
	inline uint getMapMinorVersion() const;
	inline uint getMapPatchVersion() const;
	inline std::string getMapVersionString() const;

	const Map& getMap() const;
	const Player& getPlayer() const;
};

#endif // __FILEPARSER_HPP__
