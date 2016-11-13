#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "Character.hpp"
#include "Tile.hpp"
#include "Background.hpp"
#include "Enemy.hpp"
#include <vector>
#include <memory>
typedef int Level;
typedef std::string Logger;

//temporary aliases before actual implementations added
namespace Game {
	class Engine {
	private:
		Level              currentLevel;
		sf::Texture        tempLevelTexture;//temporary before level implemented
		sf::Sprite         tempLevelSprite;
		Character          c;
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
		std::vector<Tile>    tiles;
		collisionType collisionCheck(DisplayObject& d1, DisplayObject& d2);

	public:
		Engine();
		~Engine();
		void Start();



	};
}
#endif
