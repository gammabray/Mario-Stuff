#include "Engine.hpp"
#include <algorithm>
#include <iostream>
#include <thread>




Game::Engine::Engine(int startLevel) :
	c(sf::Vector2f(640, 500)), 
	currentView(sf::Vector2f(640, 460), sf::Vector2f(1280, 720)),	
	e(sf::Vector2f(1200, 600), sf::Vector2f(16,16), 0, Game::EnemyType::TY1),
	currentLevel(Level::levelSizes.at(startLevel),startLevel),
	back(Level::levelSizes.at(startLevel)),		 
	rw(sf::VideoMode(1280, 720), "Game Title"),
	gui(),
	manager()
	
{ 
	

	rw.setFramerateLimit(120);
	
	
}



void Game::Engine::Start()

{
	sf::Event event;



	int NoOfFrames = 0 ;
	while (rw.isOpen()) {
		while (rw.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				rw.close();
			}

			if (event.type == sf::Event::KeyPressed && !keyFlag) {
				pressedKey = event.key.code;
				keyFlag = true;
			}

			else if (event.type == sf::Event::KeyReleased && keyFlag) {
				pressedKey = sf::Keyboard::Unknown;
				c.IsWalking = false;
				keyFlag = false;

			}


		}
		rw.clear();
		
		
		
		currentView.setCenter(c.getPosition().x, 460.f);
		back.draw(rw, sf::RenderStates::Default);
		currentLevel.draw(rw);
		c.Update(currentLevel);
	
		manager.CheckCollision(c, currentLevel,rw,currentView);
		if (manager.GetMinVector().x != 0 || manager.GetMinVector().y != 0) {
			c.setPosition(sf::Vector2f(c.getPosition().x + manager.GetMinVector().x, c.getPosition().y + manager.GetMinVector().y));
		}
		
	
		manager.ResetMinimumVector();
		rw.setView(currentView);
		
		
		
	//	e.update(this->c);
		


			c.Draw(rw);
			gui.update(*c.tracker, currentView);
			gui.draw(rw);
			
			
		//	e.DisplayInfo();
		//	e.Draw(rw);
			rw.display();
		
			std::cout << "frame :" << ++NoOfFrames << std::endl;

	}
}
