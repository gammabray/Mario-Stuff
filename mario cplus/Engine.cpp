#include "Engine.hpp"
#include <algorithm>


Game::Engine::Engine() : c(sf::Vector2f(600,600),sf::Vector2f(0,0)), rw(sf::VideoMode(1280,720),"hi")
{
	
	
}

Game::Engine::~Engine()
{
}

void Game::Engine::Start()
{
	sf::Event event;
	rw.setFramerateLimit(60);
	while (rw.isOpen()) {
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rw.close();
			}
			
		}
		rw.draw(c.getSprite());
		
	}
}
