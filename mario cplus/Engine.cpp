#include "Engine.hpp"
#include <algorithm>


Game::Engine::Engine() : c(sf::Vector2f(600,600),sf::Vector2f(0,0)) 
{
	rw = new sf::RenderWindow(sf::VideoMode(1280, 720), "hi");
	
}

Game::Engine::~Engine()
{
	delete rw;
}

void Game::Engine::Start()
{
	sf::Event event;
	sf::RectangleShape r;
	r.setFillColor(sf::Color::Blue);
	r.setSize(sf::Vector2f(30.f, 60.f));
	r.setPosition(sf::Vector2f(2, 3));

	rw->setFramerateLimit(60);
	while (rw->isOpen()) {
		while (rw->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rw->close();
			}
			
		}
		rw->clear();
		rw->draw(c.getSprite());
		rw->draw(r);
		rw->display();
		
	}
}
