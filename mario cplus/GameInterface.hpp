#pragma once
#ifndef GAME_INTERFACE_HPP
#define GAME_INTERFACE_HPP
#include "AnimatedObject.hpp"

namespace Game {
	class GameInterface: public sf::Drawable {
	private:
		const sf::Font font;
		std::pair<const std::string, int> score;
		std::pair<const std::string, int> lives;
		sf::Text scoreText;
	public:
		GameInterface();
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	};

}

#endif#pragma once
