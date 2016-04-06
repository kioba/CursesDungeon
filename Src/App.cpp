#include "App.hpp"

#include <sstream>
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


App& App::getInstance()
{
	static App app;
	return app;
}


bool App::init()
{
	FileParser parser("basic.cdmap");
	elements = parser.getGameELements();
	elements->player.attach(&elements->map);

	for(auto& weapon : elements->weapon_vec) {
		elements->player.attach(&weapon);
	}

	for(auto& monster : elements->monster_vec) {
		elements->player.attach(&monster);
	}

	for(auto& treasure : elements->treasure_vec) {
		elements->player.attach(&treasure);
	}

	for(auto& potion : elements->potion_vec) {
		elements->player.attach(&potion);
	}

	for(auto& trap : elements->trap_vec) {
		elements->player.attach(&trap);
	}

	for(auto& exit_door : elements->exit_vec) {
		elements->player.attach(&exit_door);
	}

	update();

	return true;
}


void App::handleInput()
{
	char answer = '-';
	std::cin >> answer;
	// std::cout << answer;
	handleMessage(answer);

	for (auto& signals : queue) {
		handleMessage(signals);
	}

	queue.clear();
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

	if (!elements->player.isAlive()) {
		pushMainEventLoop([](App& app){
			std::cout << "You Died! Press Enter to Exit!" << std::endl;
			std::string as;
			std::getline(std::cin, as);
			std::cin.get();

			app.handleMessage('q');
		});
	}
}


void App::draw()
{
	if (drawing.size() == 0) {
		return;
	}

	std::string str(drawing[0].size() * 2 + 2, '-');
	std::stringstream ss;
	ss << str << std::endl;

	for (size_t i = 0; i < drawing.size(); ++i) {
		ss << '|';

		// draw the map
		for (size_t j = 0; j < drawing[i].size(); ++j) {
			ss << drawing[i][j] << " ";
		}
		ss << '|';

		// draw the UI
		if (i == 0) {
			ss << "\tHero HP:\t" << elements->player.getHP() <<
				" / " << elements->player.getMaxHP();
		} else if(i == 1) {
			ss << "\tHero weapon:\t" <<
				(elements->player.hasWeapon() ? "[x]" : "[ ]");
		} else if(i == 2) {
			ss << "\tHero treasure:\t" <<
				(elements->player.hasTreasure() ? "[x]" : "[ ]");
		}

		ss << std::endl;
	}

	ss << str << std::endl;

	std::cout << ss.str();
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
		draw();
		handleInput();
		update();
	}

	clear();
	return 0;
}


void App::handleMessage(char mess)
{
	switch (mess) {
		case 'q':
			quit = true;
			break;

		case 'w':
			elements->player.move(UP);
			break;

		case 'a':
			elements->player.move(LEFT);
			break;

		case 's':
			elements->player.move(DOWN);
			break;

		case 'd':
			elements->player.move(RIGHT);
			break;
	}
}


void App::pushMainEventLoop(std::function<void(App&)> func)
{
	func(*this);
}
