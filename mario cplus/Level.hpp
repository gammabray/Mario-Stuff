#pragma once
#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML\Graphics.hpp>
#include <vector>
#include "Tile.hpp"
#include <fstream>
#include "AABB.hpp"
namespace Game {
	class Level : public sf::Drawable {
	private:
		std::vector<Tile> tiles;
		std::vector<AABB> collisionBoxes;
		void addTiles();
	public:
		std::vector<Tile>& getTiles() { return tiles; }
		std::vector<AABB>& getCollisionBoxes() { return collisionBoxes; }
		Level(sf::Vector2f startSize);
		void draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;

	};
}

#endif
