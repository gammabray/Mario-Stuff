#pragma once
#ifndef TILE_HPP
#define TILE_HPP
#include <SFML\Graphics.hpp>
#include <memory>
namespace Game {
	enum class tileID : char {
		DIRT = '1',
		SNOW,
		SAND,
	};
	class Tile 
		///<summary>
		///Class : Tile
		///
		///A class for each tile (Each bit of the level). Solely used by
		///the Level class to draw multiple tiles with one call of draw. 
		///</summary>

	{
	protected:
		tileID ID;
		sf::Vector2f position;
		sf::Vector2f size;

	public:
		
		std::shared_ptr<sf::Texture> texture;
		std::shared_ptr<sf::Sprite> sprite;
		sf::Vector2f& getPosition(){ return position; }
		Tile(const sf::Vector2f& startPos, const sf::Vector2f& startSize,tileID ID,sf::Texture &t = sf::Texture());
		Tile(const Tile& copy);
		
	

	};
}

#endif