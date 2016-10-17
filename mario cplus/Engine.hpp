#pragma once
#ifndef ENGINE_HPP
#define ENGINE_HPP
#include "Character.hpp"
typedef int Level;
typedef std::string Logger;
//temporary aliases before actual level added
namespace Game {
	class Engine {
	private:
		Level            currentLevel;
		Character        c;
		Logger           l;
		sf::RenderWindow rw;


	public:
		Engine();
		~Engine();
		void Start();



	};
}
#endif