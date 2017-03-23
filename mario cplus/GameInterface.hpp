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
	
		bool hasWon;
		bool lastValuesSet; //final values for score and time set
		

		std::unique_ptr<sf::Font> font;
		std::unique_ptr<sf::Texture> keyTexture;
		sf::Sprite keySprite;
		bool DrawKey;
		static std::string convertToStandardTime(sf::Time& t);
		sf::Text scoreLabel;
		sf::Text scoreValue;
		sf::Text timeLabel;
		sf::Text timeValue;
		sf::Text lifeLabel;
		sf::Text lifeValue;
		sf::Text wonLabel;

		sf::Text powerUpLabel;
		sf::Text powerUpValue;

		sf::Text finalScore;
		sf::Text finalTime;
		
	
		
		
	public:
		GameInterface();
		bool drawLast;
		void update(PlayerTracker& tracker,const sf::View& v);
		void draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;
	};

}

#endif
