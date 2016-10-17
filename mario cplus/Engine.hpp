#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "Character.hpp"
#include <vector>
typedef int Level;
typedef std::string Logger;
typedef Game::AnimatedObject Enemy;
//temporary aliases before actual implementations added
namespace Game {
	class Engine {
	private:
		Level            currentLevel;
		Character        c;
		Logger           l;
		sf::RenderWindow *rw;
		std::vector<Enemy> drawables;

	public:
		Engine();
		~Engine();
		void Start();



	};
}
#endif
