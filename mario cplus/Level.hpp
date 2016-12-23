#pragma once
#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML\Graphics.hpp>
#include <vector>
#include <fstream>
#include <forward_list>
#include "Tile.hpp"
#include "AABB.hpp"
#include "Coin.hpp"

namespace Game {
	class Level : public sf::Drawable {
	private:
		std::vector<Tile> tiles;
		std::vector<AABB> collisionBoxes;
		std::forward_list<Coin> coins; //linked list
		void addTiles();
	public:
		std::vector<Tile>& getTiles() { return tiles; }
		std::vector<AABB>& getCollisionBoxes() { return collisionBoxes; }
		Level(sf::Vector2f startSize);
		void draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;

	};
}

#endif
