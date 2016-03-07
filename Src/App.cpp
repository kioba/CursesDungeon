#include "App.hpp"

#include <iostream>
//#include <cstdlib>

// #############################################################################
// ### App #####################################################################
// #############################################################################

App::App() :
	quit{false}
{
	FileParser parser("basic.cdmap");
	elements = parser.getGameELements();
	elements->player.attach(&elements->map);
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

		case 'w':
			elements->player.move(Player::UP);
			break;

		case 'a':
			elements->player.move(Player::LEFT);
			break;

		case 's':
			elements->player.move(Player::DOWN);
			break;

		case 'd':
			elements->player.move(Player::RIGHT);
			break;
	}
}


void App::update()
{
	drawing = elements->map.getStoryMatrix();

	if (drawing.size() == 0) {
		return;
	}

	if (elements->player.getX() != -1 || elements->player.getY() != -1) {
		drawing[elements->player.getX()][elements->player.getY()] = elements->player.getDraw();
	}

	for(auto& weapon : elements->weapon_vec) {
		if ((weapon.getX() != -1 ||
			weapon.getY() != -1) &&
			weapon.isAlive())
		{
			drawing[weapon.getX()][weapon.getY()] = weapon.getDraw();
		}
	}

	for(auto& monster : elements->monster_vec) {
		if ((monster.getX() != -1 ||
			monster.getY() != -1) &&
			monster.isAlive())
		{
			drawing[monster.getX()][monster.getY()] = monster.getDraw();
		}
	}

	for(auto& treasure : elements->treasure_vec) {
		if ((treasure.getX() != -1 ||
			treasure.getY() != -1) &&
			treasure.isAlive())
		{
			drawing[treasure.getX()][treasure.getY()] = treasure.getDraw();
		}
	}

	for(auto& potion : elements->potion_vec) {
		if ((potion.getX() != -1 ||
			potion.getY() != -1) &&
			potion.isAlive())
		{
			drawing[potion.getX()][potion.getY()] = potion.getDraw();
		}
	}

	for(auto& trap : elements->trap_vec) {
		if ((trap.getX() != -1 ||
			trap.getY() != -1) &&
			trap.isAlive())
		{
			drawing[trap.getX()][trap.getY()] = trap.getDraw();
		}
	}

	for(auto& exit_door : elements->exit_vec) {
		if ((exit_door.getX() != -1 ||
			exit_door.getY() != -1) &&
			exit_door.isAlive())
		{
			drawing[exit_door.getX()][exit_door.getY()] = exit_door.getDraw();
		}
	}
}


void App::draw()
{
	if (drawing.size() == 0) {
		return;
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
