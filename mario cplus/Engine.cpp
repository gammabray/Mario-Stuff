#include "Engine.hpp"
#include "BadGuy.hpp"
#include <algorithm>
#include <iostream>
#include <thread>






Game::Engine::Engine(int startLevel) :
	c(sf::Vector2f(100, 500)), 
	currentView(sf::Vector2f(640, 460), sf::Vector2f(1280, 720)),		 
	rw(sf::VideoMode(1280, 720), "Game Title"),
	gui(),
	manager(),
	renderArea(c.getPosition().x - 1000, c.getPosition().y - 600, 2000, 1000),
	currentLevel(Level::levelSizes.at(startLevel), startLevel, renderArea),
	back(Level::levelSizes.at(startLevel)),
	finishClockStarted(false),
	saved(false)
	
{ 
	
	enemies.emplace_back(std::move(std::unique_ptr<BadGuy>(new BadGuy(sf::Vector2f(1200.f,600.f)))));
	enemies.emplace_back(std::move(std::unique_ptr<BadGuy>(new BadGuy(sf::Vector2f(1000.f, 600.f)))));

	rw.setFramerateLimit(60);

	
	
}

Game::Engine::~Engine()
{
	delete saver;
}



void Game::Engine::Start()

{
	sf::Event event;



	int NoOfFrames = 0 ;
	while (rw.isOpen()) {
		if (saved) {
			rw.close();
			return;
		}
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
				//c.IsWalking = false;
				keyFlag = false;

			}


		}
		
		rw.clear();
		currentView.setCenter(c.getPosition().x, c.getPosition().y < 800.f ? c.getPosition().y: 800.f);
		
		back.draw(rw, sf::RenderStates::Default);
		updateProjectiles();
		c.Update(currentLevel);
		
		
		updateEnemies();
		
		
	
		manager.CheckCollision(c, currentLevel,rw,currentView);
		if (manager.GetMinVector().x != 0 || manager.GetMinVector().y != 0) {
			c.setPosition(c.getPosition().x + manager.GetMinVector().x, c.getPosition().y + manager.GetMinVector().y);
		}
		if (c.getProjectileCount() > 0) { //Projectiles to be created
			switch (ProjectileType pt = c.dequeue_projectile())
			{
			case ProjectileType::p_fireball:
				projectiles.push_back(std::move(std::make_unique<Fireball>(c.getPosition(),c.getFacing())));
				break;
			default:
				break;
			}
		}
		manager.ResetMinimumVector();
		for (auto& enemy : enemies) {
			manager.CheckCollision(enemy, currentLevel);
			enemy->setPosition(enemy->getPosition().x + manager.GetMinVector().x, enemy->getPosition().y + manager.GetMinVector().y);
		}
		

		manager.ResetMinimumVector();
		renderArea.top = c.getPosition().y - 600;
		renderArea.left = c.getPosition().x - 1000;
		currentLevel.updateCheckArea(renderArea);
		currentLevel.draw(rw);
		rw.setView(currentView);
		drawProjectiles();
		drawEnemies();
		
		c.Draw(rw);
		gui.update(*c.tracker, currentView);
		gui.draw(rw);
		rw.display();
		
		//std::cout << "frame :" << ++NoOfFrames << std::endl;
		if (c.tracker->GameCompleted) {
			if (!finishClockStarted) {
				finishClock.restart();
				finishClockStarted = true;
			}			
			if (finishClock.getElapsedTime().asSeconds() > 4) {
				gui.drawLast = true;
				
			}
			if (finishClock.getElapsedTime().asSeconds() > 8) {
				saver = new ScoreSaver(*c.tracker);
				saved = saver->SaveScore(currentLevel.LevelID);
				

			}
		}

	}
}
void Game::Engine::updateEnemies()
{
	
	for (unsigned int i = 0; i < enemies.size(); ++i) {
		enemies[i]->update(c);
		if (enemies[i]->getPosition().y > 1500) {
			
			enemies.erase(enemies.begin() + i);
		}
		
	}
}

void Game::Engine::drawEnemies()
{
	for (auto& enemy : enemies) {
		enemy->Draw(rw);
	}
}

void Game::Engine::updateProjectiles()
{
	for (unsigned int i = 0; i < projectiles.size(); ++i) {

		projectiles[i]->update();
		if (projectiles[i]->getTimeRemaining().asSeconds() > 0.5) {
			projectiles.erase(projectiles.begin() + i);
		}
		else if (projectiles[i]->getPosition().x > currentView.getCenter().x + 1000 || projectiles[i]->getPosition().x < currentView.getCenter().x - 1000) {

			projectiles.erase(projectiles.begin() + i);
		}

	}
}

void Game::Engine::drawProjectiles()
{
	for (auto& projectile : projectiles) {
		projectile->Draw(rw);
	}
}

