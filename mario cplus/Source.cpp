#include "Engine.hpp"


int main() {
	Game::Background::s_addTextures();
	Game::Engine Engine(0);
	Engine.Start();



}