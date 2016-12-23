#pragma once
#ifndef TILE_HPP
#define TILE_HPP
#include <SFML\Graphics.hpp>
#include <memory>
#include "DisplayObject.hpp"
namespace Game {
	enum tileID : char {
		DIRT = '1',
		SNOW,
		SAND,
	};
	class Tile : public DisplayObject
		///<summary>
		///Class : Tile
		///
		///A class for each tile (Each bit of the level). Solely used by
		///the Level class to draw multiple tiles with one call of draw. 
		///</summary>

	{
	protected:
		tileID ID;
	public:
		
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default);
		Tile(const sf::Vector2f& startPos, const sf::Vector2f& startSize,tileID ID,sf::Texture &t = sf::Texture());
		
		
	

	};
}

#endif