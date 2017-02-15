#include "Engine.hpp"
#include "BadGuy.hpp"
#include <algorithm>
#include <iostream>
#include <thread>
#import <C:\\Program Files (x86)\\Common Files\\System\\ado\\msado15.dll> rename( "EOF", "AdoNSEOF" )





Game::Engine::Engine(int startLevel) :
	c(sf::Vector2f(640, 500)), 
	currentView(sf::Vector2f(640, 460), sf::Vector2f(1280, 720)),	
	currentLevel(Level::levelSizes.at(startLevel),startLevel), 
	back(Level::levelSizes.at(startLevel)),		 
	rw(sf::VideoMode(1280, 720), "Game Title"),
	gui(),
	manager()
	
{ 
	std::shared_ptr<BadGuy> bg = std::make_shared<BadGuy>(sf::Vector2f(1200.f, 600.f));
	enemies.emplace_back(bg);
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
		
		c.Update(currentLevel);
		updateEnemies();
		
	
		manager.CheckCollision(c, currentLevel,rw,currentView);
		if (manager.GetMinVector().x != 0 || manager.GetMinVector().y != 0) {
			c.setPosition(c.getPosition().x + manager.GetMinVector().x, c.getPosition().y + manager.GetMinVector().y);
		}
		manager.ResetMinimumVector();
		for (auto enemy : enemies) {
			manager.CheckCollision(enemy, currentLevel);
			enemy->setPosition(enemy->getPosition().x + manager.GetMinVector().x, enemy->getPosition().y + manager.GetMinVector().y);
		}
	
		manager.ResetMinimumVector();
		currentLevel.draw(rw);
		rw.setView(currentView);
		drawEnemies();
		c.Draw(rw);
		gui.update(*c.tracker, currentView);
		gui.draw(rw);
		rw.display();
		
		std::cout << "frame :" << ++NoOfFrames << std::endl;
		if (c.tracker->GameCompleted) {
		
		}

	}
}
void Game::Engine::updateEnemies()
{
	
	for (int i = 0; i < enemies.size(); ++i) {
		enemies[i]->update(c);
		if (enemies[i]->getPosition().y > 1500) {
			
			enemies.erase(enemies.begin() + i);
		}
		
	}
}

void Game::Engine::drawEnemies()
{
	for (auto enemy : enemies) {
		enemy->Draw(rw);
	}
}

