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
#include "ScoreSaver.hpp"
#include <vector>
#include <memory>





namespace Game {
	typedef std::string Logger;
	
	

	class Engine {
	private:
		Level              currentLevel; //The level currently loaded
		Character          c;			 
		EnemyList          enemies;	     //Vector of pointers to enemies
		ProjectileList	   projectiles;  //The projectiles currently in the game
		WorldManager       manager;		 //Manages object states w/ collision
		sf::RenderWindow   rw;			 //The window to be drawn to 
		sf::View           currentView;  //The camera : where the window is looking at
		sf::Keyboard::Key  pressedKey;
		Background		   back;		 //The background behind the level
		bool               keyFlag;
		GameInterface	   gui;			 //The HUD which shows the player's progress
		sf::FloatRect      renderArea;   //The area the window should render
		sf::Clock		   finishClock;  //Clock to keep time of level endings
		ScoreSaver*		   saver;
		bool			   finishClockStarted;
		bool			   saved;
		void updateEnemies();
		void drawEnemies();

		void updateProjectiles();
		void drawProjectiles();
	
	
	public:
		
		Engine(int startLevel);
		~Engine();
		void Start();



	};
}
#endif
