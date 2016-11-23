#pragma once
#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML\Graphics.hpp>
#include <vector>
#include "Tile.hpp"
#include <fstream>
namespace Game {
	class Level : public sf::Drawable {
	private:
		std::vector<Tile> tiles;
		std::vector<sf::FloatRect> collisionBoxes;
		void addTiles();
	public:
		std::vector<Tile>& getTiles() { return tiles; }
		Level(sf::Vector2f startSize);
		void draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;

	};
}

#endif
