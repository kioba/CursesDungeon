#ifndef __FILEPARSER_HPP__
#define __FILEPARSER_HPP__

#include <string>
#include <vector>
#include <memory>
#include "Defines.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Story.hpp"
#include "GameObjects.hpp"

class FileParser;

class GameElements
{
public: /* variables */
	Map map;
	Player player;

	std::vector<Weapon> weapon_vec;
	std::vector<Monster> monster_vec;
	std::vector<Treasure> treasure_vec;
	std::vector<Potion> potion_vec;
	std::vector<Trap> trap_vec;
	std::vector<Exit> exit_vec;

public: /* functions */
	GameElements();
	virtual ~GameElements();
};


class FileParser
{
private: /* variables */
	std::vector<std::string> vec;

	uint major_version;
	uint minor_version;
	uint patch_version;

	std::shared_ptr<GameElements> elements;
	std::unique_ptr<Story> story;

	void createGameElement(char source, Pos pos);

public: /* function */
	FileParser(std::string path);
	virtual ~FileParser();

	void print() const;

	inline uint getMapMajorVersion() const;
	inline uint getMapMinorVersion() const;
	inline uint getMapPatchVersion() const;
	inline std::string getMapVersionString() const;

	std::shared_ptr<GameElements> getGameELements() const;
};

#endif // __FILEPARSER_HPP__
