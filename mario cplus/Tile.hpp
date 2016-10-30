#pragma once
#ifndef TILE_HPP
#define TILE_HPP
#include <SFML\Graphics.hpp>
#include "DisplayObject.hpp"
namespace Game {
	class Tile : public DisplayObject
	{
	protected:
		

	public:
		Tile(const Vector2f& startPos, const Vector2f& startSize,sf::Texture t = sf::Texture());
		~Tile();
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default);

	};
}

#endif