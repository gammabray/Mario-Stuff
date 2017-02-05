#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "Character.hpp"
#include "Tile.hpp"
#include "Background.hpp"
#include "Enemy.hpp"
#include "Level.hpp"
#include "GameInterface.hpp"
#include "WorldManager.hpp"
#include <vector>
#include <memory>





namespace Game {
	typedef std::string Logger;
	typedef std::vector<std::shared_ptr<Enemy>> enemyList;
	class Engine {
	private:
		Level              currentLevel;
		sf::Texture        tempLevelTexture;//temporary before level implemented
		sf::Sprite         tempLevelSprite;
		Character          c;
		enemyList          enemies;
		Logger             l;
		WorldManager   manager;
		sf::RenderWindow   rw;
		sf::View           currentView;
		sf::Keyboard::Key  pressedKey;
		Background		   back;
		bool               keyFlag;
		GameInterface	   gui;
		
		void updateEnemies();
		void drawEnemies();
	
	
	public:
		
		Engine(int startLevel);
		
		void Start();



	};
}
#endif
