#ifndef __FILEPARSER_HPP__
#define __FILEPARSER_HPP__

#include <string>
#include <vector>
#include <memory>
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

	std::shared_ptr<Story> story;
	std::shared_ptr<Player> player;

	void createGameElement(FIELDTYPE type, Pos pos);

public: /* function */
	FileParser(std::string path);
	virtual ~FileParser();

	void print() const;

	inline uint getMapMajorVersion() const;
	inline uint getMapMinorVersion() const;
	inline uint getMapPatchVersion() const;
	inline std::string getMapVersionString() const;

	const std::shared_ptr<Story> getMap() const;
	const std::shared_ptr<Player> getPlayer() const;
};

#endif // __FILEPARSER_HPP__
