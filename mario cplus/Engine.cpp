#include "Engine.hpp"
#include <algorithm>
#include <iostream>


Game::Engine::Engine() : c(sf::Vector2f(600,600),sf::Vector2f(0,0)),currentView(sf::Vector2f(640,360),sf::Vector2f(1280,720))
						

{
	rw = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game Title");
	if (!tempLevelTexture.loadFromFile("Images\\level.png")) {
		std::cout << "Failed to load Level Image..." << std::endl;
	}
	tempLevelSprite.setTexture(tempLevelTexture);
	
}

Game::Engine::~Engine()
{
	delete rw;
	for (auto object : drawables)
	{
		delete object;
	}
	
	
}

void Game::Engine::Start()
{
	sf::Event event;
	
	std::cout << sf::Texture::getMaximumSize() << std::endl;
	c.IsWalking = true;
	rw->setFramerateLimit(60);
	while (rw->isOpen()) {
		while (rw->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rw->close();
			}
			pressedKey = event.key.code;
			
		}
		rw->clear();
		rw->setView(currentView);
		c.update(currentView, c.IsWalking ? pressedKey : sf::Keyboard::Unknown);
		
		c.Draw(*rw);
		for (Tile tile : tiles) {
			tile.Draw(*rw, sf::RenderStates::Default);
		}
		
		rw->display();
		
		
	}
}
