#include "Level.hpp"
#include <cmath>

void Game::Level::addTiles() //generate tiles and collsion boxes
{
	std::ifstream input;
	std::vector<std::string> layout;
	input.open("Levels\\testlevel.txt",std::ios::in);
	while(!input.eof()) {
		std::string s;
		std::getline(input,s);
		layout.push_back(s);		 
	}
	input.close();
	sf::Vector2f currentPos;//current position of tile creator
	const float xOffset = 32;
	const float yOffset = 32;
	
	float groundLevel;
	//add tiles
	int count = 0;
	for (std::string& s : layout) {
		for (char& c : s){
			if (c == tileID::DIRT) {
				tiles.push_back(Tile(currentPos, sf::Vector2f(32, 32),tileID::DIRT));
				//the if statement above adds a tile to the container of tiles if
				//the given character in the string is a tile ( not just air)
				//the last line converts the ASCII character to its int value by 
				//reducing the character by the value of the character 0.

				
			}
			else if (c == Coin::s_ID) {
				coins.emplace_back(sf::Vector2f(currentPos.x, currentPos.y - 16));
				//coins are created in the middle/top of the tile grid
																				   
			}
			count++;
			
			currentPos.x += xOffset;

		}
		currentPos.x = 0;
		currentPos.y += yOffset;

	}
	
	groundLevel = currentPos.y;

	//create collsion boxes for level

	int currTile = 0;
	float currTileYpos = tiles[0].getPosition().y;
	sf::Vector2f topleft(0, currTileYpos);
	sf::Vector2f topright;
	float bot = 0;
	printf("%d", tiles.size());
	fflush(stdout);

	
	
	

	
	

}

Game::Level::Level(sf::Vector2f startSize)
{
	addTiles();

}

void Game::Level::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& coin : coins) {
		target.draw(coin.getSprite());
	}
	for (auto& tile : tiles) {
		target.draw(tile.getSprite());
	}
}

void Game::Level::eraseCoin(int index)
{
	try {
		this->coins.erase(coins.begin() + index);
	}
	catch (std::out_of_range e) {
		std::cout << e.what() << std::endl;
	}
	
}
