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
			if (c == '1') {
				tiles.push_back(Tile(currentPos, sf::Vector2f(32, 32), static_cast<int>(c - '0')));
				//the if statement above adds a tile to the container of tiles if
				//the given character in the string is a tile ( not just air)
				//the last line converts the ASCII character to its int value by 
				//reducing the character by the value of the character 0.

				count++;
			}
				
			
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

	
	
	for (Tile& t : tiles) {

		collisionBoxes.push_back(AABB(sf::Vector2f(xOffset,yOffset),t.getPosition()));
	}

	
	

}

Game::Level::Level(sf::Vector2f startSize)
{
	addTiles();

}

void Game::Level::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& tile : tiles) {
		target.draw(*tile.sprite);
	}
}
