#include "Engine.hpp"


int main() {

	Game::Background::s_addTextures();
	Game::Engine engine;
	engine.Start();
	
	
	return 0;
	

}