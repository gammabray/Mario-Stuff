#include "Engine.hpp"
#include <algorithm>
#include <iostream>



Game::Engine::Engine() : c(sf::Vector2f(600,600),sf::Vector2f(12,6)),currentView(sf::Vector2f(640,360),sf::Vector2f(1280,720)),back(sf::Vector2f(4000,720))

{ 

	rw = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game Title");
	if (!tempLevelTexture.loadFromFile("Images\\level.png")) {
		std::cout << "Failed to load Level Image..." << std::endl;
	}
	
	
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
	
	rw->setFramerateLimit(60);
	while (rw->isOpen()) {
		while (rw->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rw->close();
			}
			if (event.type == sf::Event::KeyPressed && !keyFlag) {
				pressedKey = event.key.code;
				keyFlag = true;
			}
				
			if (event.type == sf::Event::KeyReleased && keyFlag ) {
				pressedKey = sf::Keyboard::Unknown;
				keyFlag = false;

			}

			
		}
		rw->clear();
		rw->setView(currentView);
//		back.draw(*rw, sf::RenderStates::Default);
		c.update(currentView, pressedKey);
	
		c.DisplayInfo();
		c.Draw(*rw);
		
		
		rw->display();
		
		
	}
}
Game::Engine::collisionType Game::Engine::collisionCheck(DisplayObject & d1, DisplayObject & d2)
	//NOTE: d1 should be the character in character - other object collisions
{
	if (!d1.getCollisionBox().intersects(d2.getCollisionBox())) {
		return collisionType::NOCOL;
	}
	else return collisionType::GENERIC;
		
}

