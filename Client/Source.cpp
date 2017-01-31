#include "..\mario cplus\Engine.hpp"
#include "..\mario cplus\Background.hpp"
int main() {

	Game::Background::s_addTextures();
	Game::Engine engine(0);
	engine.Start();
	return 0;
}