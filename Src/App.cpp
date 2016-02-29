#include "App.hpp"

#include <iostream>
#include <cstdlib>

// #############################################################################
// ### App #####################################################################
// #############################################################################

App::App() :
	quit{false},
	player{Pos(-1, -1)}
{
	FileParser parser("basic.cdmap");
	map = parser.getMap();
	player = parser.getPlayer();
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
	// map.printMap();
	Matrix<char> drawing = map.getStoryMatrix("story 0:");

	if (drawing.size() == 0) {
		return;
	}

	if (player.getX() != -1 || player.getY() != -1) {
		drawing[player.getX()][player.getY()] = 'h';
	}

	std::string str(drawing[0].size() * 2 + 2, '-');
	std::cout << str << std::endl;

	for (size_t i = 0; i < drawing.size(); ++i) {
		std::cout << '|';
		for (size_t j = 0; j < drawing[i].size(); ++j) {
			std::cout << drawing[i][j] << " ";
		}
		std::cout << '|' << std::endl;
	}

	std::cout << str << std::endl;
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
