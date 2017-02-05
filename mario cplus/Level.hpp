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

namespace Game {
	class Level : public sf::Drawable {
	private:
	
		void addTiles(int levelID);
		const static int testLevelID = 0;
	public:														  
		std::vector<Tile> tiles;
		std::vector<Coin> coins;
		const static std::unordered_map<int,sf::Vector2f> levelSizes;
		Level(sf::Vector2f startSize,int levelID);
		void draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;
		void eraseCoin(int index);
		sf::Vector2f respawnPoint;
	};
}

#endif
