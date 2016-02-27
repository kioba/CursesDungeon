#include "App.hpp"

#include <iostream>
#include <cstdlib>

// #############################################################################
// ### App #####################################################################
// #############################################################################

App::App() :
	quit{false},
	parser{"basic.cdmap"}
{
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
	parser.print();
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
		clearScreen();
		update();
		draw();
		handleInput();
	}

	clear();
	return 0;
}
