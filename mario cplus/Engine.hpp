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
#include "Projectile.hpp"
#include "Fireball.hpp"
#include <vector>
#include <memory>





namespace Game {
	typedef std::string Logger;
	typedef std::vector<std::unique_ptr<Enemy>> EnemyList;
	typedef std::vector<std::unique_ptr<Projectile>> ProjectileList;

	class Engine {
	private:
		Level              currentLevel;
		sf::Texture        tempLevelTexture;//temporary before level implemented
		sf::Sprite         tempLevelSprite;
		Character          c;
		EnemyList          enemies;
		ProjectileList	   projectiles;
		Logger             l;
		WorldManager   manager;
		sf::RenderWindow   rw;
		sf::View           currentView;
		sf::Keyboard::Key  pressedKey;
		Background		   back;
		bool               keyFlag;
		GameInterface	   gui;
		sf::FloatRect renderArea;
		void updateEnemies();
		void drawEnemies();

		void updateProjectiles();
		void drawProjectiles();
	
	
	public:
		
		Engine(int startLevel);
		
		void Start();



	};
}
#endif
