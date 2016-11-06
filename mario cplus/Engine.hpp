#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "Character.hpp"
#include "Tile.hpp"
#include "Background.hpp"
#include <vector>
typedef int Level;
typedef std::string Logger;
typedef Game::AnimatedObject Enemy;
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

		std::vector<Enemy*>          drawables;
		std::vector<Tile>            tiles;

	public:
		Engine();
		~Engine();
		void Start();



	};
}
#endif
