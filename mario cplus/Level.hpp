#pragma once
#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML\Graphics.hpp>
#include <vector>
#include <fstream>
#include "Tile.hpp"
#include "AABB.hpp"
#include "Coin.hpp"
#include <unordered_map>
#include "PowerUp.hpp"

namespace Game {
	class PowerUp;
	class Level : public sf::Drawable {
	private:
	
		void addTiles(int levelID);
		void loadXml(int levelID);
		
		const static int testLevelID = 0;
		static std::map<int, std::string> imageFilepaths;
		sf::FloatRect checkArea;
	public:														  
		std::vector<Tile> tiles;
		std::vector<Coin> coins;
		std::vector<PowerUp> powerUps;
	
		const static std::unordered_map<int,sf::Vector2f> levelSizes;
		Level(sf::Vector2f startSize, int levelID, sf::FloatRect renderArea);
		void draw(sf::RenderTarget & target ,sf::RenderStates states = sf::RenderStates::Default) const;
		void updateCheckArea(sf::FloatRect& newArea) { checkArea = newArea;}
		void eraseCoin(int index);
		void erasePowerUp(int index);
		sf::Vector2f respawnPoint;
	};
}

#endif
