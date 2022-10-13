#pragma once
#include "Menu.h"


int main() try
{
	while (true)
	{
		Menu startMenu;
		startMenu.run();
	}
	return EXIT_SUCCESS;
}

catch (std::exception & e)
{
	std::cerr << "Exception: " << e.what() << std::endl;
	return EXIT_FAILURE;
}
catch (...)
{
	std::cerr << "Unknown exception "<< std::endl;
	return EXIT_FAILURE;
}