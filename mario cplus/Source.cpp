#include "Engine.hpp"


int main(int startLevel) {
	Game::Background::s_addTextures();
	Game::Engine Engine(0);
	Engine.Start();



}