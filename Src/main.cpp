#include <iostream>
#include "App.hpp"

int main(int argc, char* args[])
{
	(void)argc;
	(void)args;

	return App::getInstance().execute();
}
