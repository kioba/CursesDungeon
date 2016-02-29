#ifndef __APP_HPP__
#define __APP_HPP__

#include "FileParser.hpp"
#include "Map.hpp"
#include "Player.hpp"

// #############################################################################
// ### App #####################################################################
// #############################################################################

class App
{
private: /* variables */
	bool quit;
	Map map;
	Player player;

protected: /* functions */
	bool init();
	void handleInput();
	void update();
	void draw();
	void clear();

	inline void clearScreen() const;
public: /* functions */

	App();
	virtual ~App();

	int execute();
};

#endif // __APP_HPP__
