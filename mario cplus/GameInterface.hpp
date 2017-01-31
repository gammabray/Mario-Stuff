#pragma once
#ifndef GAME_INTERFACE_HPP
#define GAME_INTERFACE_HPP
#include "AnimatedObject.hpp"
#include "PlayerTracker.hpp"
#include <sstream>
#include <iomanip>

namespace Game {
	class PlayerTracker; // forward declaration
	class GameInterface: public sf::Drawable {
	private:
	

		std::unique_ptr<sf::Font> font;
		static std::string convertToStandardTime(sf::Time& t);
		sf::Text scoreLabel;
		sf::Text scoreValue;
		sf::Text timeLabel;
		sf::Text timeValue;
		sf::Text lifeLabel;
		sf::Text lifeValue;
	
		
		
	public:
		GameInterface();
		
		void update(PlayerTracker& tracker,const sf::View& v);
		void draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;
	};

}

#endif
