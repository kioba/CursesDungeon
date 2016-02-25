#include "App.hpp"

#include <iostream>
// #############################################################################
// ### App #####################################################################
// #############################################################################

App::App() :
	quit{false}
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
	
}


void App::clear()
{
}


int App::execute()
{
	if (!init()) {
		return 1;
	}

	while (!quit) {
		handleInput();
		update();
		draw();
	}

	clear();
	return 0;
}
