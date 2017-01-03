#include "Engine.hpp"
int main() {
	Game::Background::s_addTextures();
	Game::Engine engine(1);
	engine.Start();
	return 0;

}