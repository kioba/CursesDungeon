#ifndef __APP_HPP__
#define __APP_HPP__

// #############################################################################
// ### App #####################################################################
// #############################################################################

class App
{
private: /* variables */
	bool quit;

protected: /* functions */
	bool init();
	void handleInput();
	void update();
	void draw();
	void clear();

public: /* functions */

	App();
	virtual ~App();

	int execute();
};

#endif // __APP_HPP__
