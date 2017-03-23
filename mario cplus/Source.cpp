#include "Engine.hpp"
#include "TinyXML\tinyxml2.h"
#include <sstream>
#include <Windows.h>
namespace XML = tinyxml2;

int main(int argc, char** argv) {
	std::cout << argc << std::endl;
	int startLevel;
	if (argc > 1) {		
			startLevel = atoi(argv[1]);//converts a string to its int value
	}
	else {
		startLevel = 2;
	}
	Game::Background::s_addTextures();
	Game::Engine Engine(startLevel);
	FreeConsole();
	Engine.Start();

	return EXIT_SUCCESS;
	


}