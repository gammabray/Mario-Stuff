#pragma once
#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include <SFML\Graphics.hpp>
#include <vector>
#include <array>
#include <memory>


//Class to render the background efficiently (i.e only render the background where the player is)
//Splits background into 1000x1024 chunks to render induvidually
namespace Game {
	class BackgroundTile {//nested class to represent each 'portion' of the background 
	public:
		std::shared_ptr<sf::Texture> texture;
		sf::Vector2f position;
		static const sf::Vector2f s_tilesize;
		std::shared_ptr<sf::Sprite> sprite;
		BackgroundTile(sf::Vector2f position, sf::Texture& t);
		BackgroundTile(const BackgroundTile& copy);//copy constructor for addition to vector
		
		

	};
	class Background : public sf::Drawable {
	private:
		
		
		std::vector<BackgroundTile> backTiles;//container of background tiles
		static std::vector<std::string> s_filepaths;//filepaths of tile images
		static std::vector<std::shared_ptr<sf::Texture>> s_blockTextures;//pointers to the texture
		void generateBackgroundTiles(int NoOfTiles);//create background tiles based off of how big the level is
		sf::Vector2f levelSize;
	public:
		static void s_addTextures();
		
		Background(sf::Vector2f levelsize);
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;//draw all to screen
		

	};
}
#endif