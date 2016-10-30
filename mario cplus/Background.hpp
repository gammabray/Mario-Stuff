#pragma once
#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include <SFML\Graphics.hpp>
#include <vector>

//Used to render the background efficiently (i.e only render the background where the player is)
namespace Game {
	class Background : public sf::Drawable {
	private:
		struct BackgroundTile {//nested structure to represent each 'portion' of the background 
			sf::Texture*  texture;
			sf::Vector2f* position;
			static const sf::Vector2f size;
			sf::Sprite* sprite;
			BackgroundTile(sf::Vector2f position, sf::Texture t);
			~BackgroundTile();
		

		};
		std::vector<BackgroundTile> background;
	public:
		void Draw(sf::RenderTarget & target, sf::RenderStates & states) {

		}

	};
}
#endif