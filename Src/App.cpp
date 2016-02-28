#include "App.hpp"

#include <iostream>
#include <cstdlib>

// #############################################################################
// ### App #####################################################################
// #############################################################################

App::App() :
	quit{false}
{
	FileParser parser("basic.cdmap");
	map = parser.getMap();
}


App::~App()
{
}


bool App::init()
{
	return true;
}


void App::handleInput()
{
	char answer = '-';
	std::cin >> answer;
	// std::cout << answer;

	switch (answer) {
		case 'q':
			quit = true;
			break;
	}
}


void App::update()
{
}


void App::draw()
{
	map.printMap();
}


void App::clear()
{
}


void App::clearScreen() const
{
#ifdef WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}


int App::execute()
{
	if (!init()) {
		return 1;
	}

	while (!quit) {
		update();
		clearScreen();
		draw();
		handleInput();
	}

	clear();
	return 0;
}
