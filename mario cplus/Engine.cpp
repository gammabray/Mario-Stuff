#include "Engine.hpp"
#include <algorithm>
#include <iostream>
#include <thread>




Game::Engine::Engine() :
	//This is a C++ initialization list.
	//It is used to directly initialize the non pointer fields of the class.

	c(sf::Vector2f(600, 600), sf::Vector2f(6, 12)), currentView(sf::Vector2f(640, 360), sf::Vector2f(1280, 720)),
	back(sf::Vector2f(4000, 720)),
	e(sf::Vector2f(1200, 600), sf::Vector2f(16,16), 0, Game::EnemyType::TY1),
	currentLevel(sf::Vector2f(4000,720))
	
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

			else if (event.type == sf::Event::KeyReleased && keyFlag) {
				pressedKey = sf::Keyboard::Unknown;
				c.IsWalking = false;
				keyFlag = false;

			}


		}
		rw->clear();
		rw->setView(currentView);
		//back.draw(*rw, sf::RenderStates::Default);
		currentLevel.draw(*rw);
		c.update(currentView);
		e.update(c);
		if (collisionCheck(c, e) == collisionType::GENERIC) {
			c.hit(*rw);
			std::this_thread::sleep_for(std::chrono::milliseconds(10000));
			return;
		};



			c.Draw(*rw);
			//e.DisplayInfo();
			e.Draw(*rw);
			rw->display();


		}
	}
Game::Engine::collisionType Game::Engine::collisionCheck(Character & c, Tile & t)
{
	sf::FloatRect checkBox(c.getPosition().x - 640, 0.f, 1280, 720.f);
	if (!checkBox.contains(t.getPosition())) {//filter out tiles not in the immediate area
		return collisionType::NOCOL;
	}
	else {

	}
}

Game::Engine::collisionType Game::Engine::collisionCheck(Character & ch, Enemy & e)
{
	if (c.IsJumping && ch.getCollisionBox().intersects(e.getCollisionBox())) {
		return collisionType::TOP;
	}
	else if (ch.getCollisionBox().intersects(e.getCollisionBox())) {
		return collisionType::GENERIC;
	}
	return collisionType::NOCOL;
}

