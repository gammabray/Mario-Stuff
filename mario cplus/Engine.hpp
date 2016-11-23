#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "Character.hpp"
#include "Tile.hpp"
#include "Background.hpp"
#include "Enemy.hpp"
#include "Level.hpp"
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
		sf::RenderWindow  *rw;
		sf::View           currentView;
		sf::Keyboard::Key  pressedKey;
		Background		   back;
		bool               keyFlag;
		enum class collisionType {
			TOP,
			LEFT,
			RIGHT,
			BOTTOM,
			NOCOL,
			GENERIC,
		};
		std::vector<Enemy*>  drawables;
		
						  		
		
		collisionType collisionCheck(Character& ch, Enemy& e);//Character/enemy collision
		collisionType collisionCheck(Enemy& e, Level& l);//Enemy/Tile collision
		collisionType collisionCheck(Enemy& e1, Enemy& e2);//Enemy-Enemy collision
		collisionType collisionCheck(Character& c, Tile& t);//Character/level collision
	public:
		
		Engine();
		~Engine();
		void Start();



	};
}
#endif
