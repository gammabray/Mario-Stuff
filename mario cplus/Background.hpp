#pragma once
#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include <SFML\Graphics.hpp>
#include <vector>
#include <array>
#include <memory>
#define DEBUG = true

//Class to render the background efficiently (i.e only render the background where the player is)
//Splits background into 1000x1024 chunks to render induvidually
namespace Game {
	class BackgroundTile {//nested class to represent each 'portion' of the background 
	public:
		std::unique_ptr<sf::Texture> texture;
		sf::Vector2f position;
		static const sf::Vector2f s_tilesize;
		std::unique_ptr<sf::Sprite> sprite;
		BackgroundTile(sf::Vector2f position, sf::Texture& t);
		BackgroundTile(const BackgroundTile& copy);//copy constructor for addition to vector
		//this was added in to keep the unique_ptr's
		~BackgroundTile();

	};
	class Background : public sf::Drawable {
	private:
		
		
		std::vector<BackgroundTile> backTiles;//container of background tiles
		static std::vector<std::string> s_filepaths;//filepaths of tile images
		static std::vector<std::unique_ptr<sf::Texture>> s_blockTextures;//pointers to the texture
		void generateBackgroundTiles(int NoOfTiles);//create background tiles based off of how big the level is
		sf::Vector2f levelSize;
	public:
		static void addTextures();
		static void deleteTextures();
		Background(sf::Vector2f levelsize);
		void draw(sf::RenderTarget & target, sf::RenderStates states) const;//draw all to screen
		

	};
}
#endif