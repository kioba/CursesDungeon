#ifndef __APP_HPP__
#define __APP_HPP__

#include "FileParser.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include <functional>

// #############################################################################
// ### App #####################################################################
// #############################################################################

class App
{
private: /* variables */
	bool quit;

	std::shared_ptr<GameElements> elements;
	Matrix<char> drawing;
	std::vector<char> queue;

private: /* functions */
	App();
	virtual ~App();
	App(const App& app) = delete;
	App& operator=(const App& app) = delete;

protected: /* functions */
	bool init();
	void handleInput();
	void update();
	void draw();
	void clear();

	inline void clearScreen() const;

public: /* functions */

	static App& getInstance();
	int execute();
	void handleMessage(char mess);
	void pushMainEventLoop(std::function<void(App&)> func);
};

#endif // __APP_HPP__
