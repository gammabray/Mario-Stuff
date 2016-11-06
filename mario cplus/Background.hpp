#pragma once
#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include <SFML\Graphics.hpp>
#include <vector>
#include <array>
#define DEBUG = true

//Used to render the background efficiently (i.e only render the background where the player is)
namespace Game {

	class Background : public sf::Drawable {
	private:
		struct BackgroundTile {//nested structure to represent each 'portion' of the background 
			sf::Texture*  texture;
			sf::Vector2f* position;
			static const sf::Vector2f s_tilesize;
			sf::Sprite* sprite;
			BackgroundTile(sf::Vector2f position, sf::Texture t);
			~BackgroundTile();
		

		};
		std::vector<BackgroundTile> backTiles;
		static std::vector<std::string> s_filepaths;
		static std::vector<sf::Texture*> s_blockTextures;
		void generateBackgroundTiles(int NoOfTiles);
	public:
		static void addTextures();
		Background(sf::Vector2f levelsize);
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;
		

	};
}
#endif