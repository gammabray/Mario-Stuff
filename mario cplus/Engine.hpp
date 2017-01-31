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


typedef std::string Logger;

//temporary aliases before actual implementations added
namespace Game {
	class Engine {
	private:
		Level              currentLevel;
		sf::Texture        tempLevelTexture;//temporary before level implemented
		sf::Sprite         tempLevelSprite;
		Character          c;
		Enemy			   e;
		Logger             l;
		WorldManager   manager;
		sf::RenderWindow   rw;
		sf::View           currentView;
		sf::Keyboard::Key  pressedKey;
		Background		   back;
		bool               keyFlag;
		GameInterface	   gui;
		
		
	
	public:
		
		Engine(int startLevel);
		
		void Start();



	};
}
#endif
