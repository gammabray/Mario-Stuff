#include "Engine.hpp"


int main() {

	Game::Background::addTextures();
	Game::Engine engine;
	engine.Start();
	Game::Background::deleteTextures();
	
	return 0;
	

}