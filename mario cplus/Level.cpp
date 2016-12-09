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
	const float xOffset = 12;
	const float yOffset = 12;
	
	float groundLevel;
	//add tiles
	int count = 0;
	for (std::string& s : layout) {
		for (char& c : s){
			if (c == '1') {
				tiles.push_back(Tile(currentPos, sf::Vector2f(12, 12), static_cast<int>(c - '0')));
				//the if statement above adds a tile to the container of tiles if
				//the given character in the string is a tile ( not just air)
				//the last line converts the ASCII character to its int value (not it's ascii code)

				count++;
			}
				
			
			currentPos.x += xOffset;

		}
		currentPos.x = 0;
		currentPos.y += yOffset;

	}
	tiles.shrink_to_fit();
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
//		collisionBoxes.push_back(sf::FloatRect(t.getPosition().x, t.getPosition().y, 12, 12);
		collisionBoxes.push_back(AABB(sf::Vector2f(12,12),t.getPosition()));
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
