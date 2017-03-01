#include "Engine.hpp"
#include <sstream>


int main(int argc, char** argv) {
	std::cout << argc << std::endl;
	int startLevel;
	if (argc > 1) {		
			startLevel = atoi(argv[1]);//converts a string to its int value
	}
	else {
		startLevel = 0;
	}
	Game::Background::s_addTextures();
	Game::Engine Engine(startLevel);
	Engine.Start();



}