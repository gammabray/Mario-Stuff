#pragma once
#ifndef TILE_HPP
#define TILE_HPP
#include <SFML\Graphics.hpp>
#include <memory>
namespace Game {
	typedef int TileID;
	class Tile 
		///<summary>
		///Class : Tile
		///
		///A class for each tile (Each bit of the level). Solely used by
		///the Level class to draw multiple tiles with one call of draw. 
		///</summary>
	{
	protected:
		TileID ID;
		sf::Vector2f position;
		sf::Vector2f size;

	public:
		std::unique_ptr<sf::Texture> texture;
		std::unique_ptr<sf::Sprite> sprite;
		sf::Vector2f& getPosition(){ return position; }
		Tile(const sf::Vector2f& startPos, const sf::Vector2f& startSize,TileID ID,sf::Texture &t = sf::Texture());
		Tile(const Tile& copy);
		~Tile();
	

	};
}

#endif