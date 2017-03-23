#include "Level.hpp"
#include <cmath>
#include "TinyXML\tinyxml2.h"
const int Game::Level::testLevelID;
std::map<int, std::string> Game::Level::imageFilepaths;
const std::unordered_map<int, sf::Vector2f> Game::Level::levelSizes = { {1,sf::Vector2f(8000,1000)},{0,sf::Vector2f(8000,1000) },{2,sf::Vector2f(8000,1000) } };


void Game::Level::loadXml(int levelID)
{
	
	
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError result = xmlDoc.LoadFile("Levels//test.tmx");
	//get <tileset> subtree
	auto tileset = xmlDoc.FirstChild()
		->NextSibling()
		->FirstChild();
	//Loop through tree and store location of filepath of each tile id
	for (auto ele = tileset->FirstChild()->ToElement();
		ele->NextSibling() != nullptr;
		ele = ele->NextSibling()->ToElement())
	{
		auto tempString = std::string(ele->FirstChildElement()->Attribute("source"));
		int size = tempString.size();
		
		tempString.erase(0, 3);
		imageFilepaths.insert(
			std::pair<int, std::string>(
				std::stoi(ele->Attribute("id")) + 1,
				tempString
			)
		);
	}
	//Get first <tile> value
	auto tileData = xmlDoc.FirstChild()
		->NextSibling()
		->FirstChild()
		->NextSibling()
		->FirstChild(); //Get tile data


	sf::Vector2f currentPos(0, 0);
	const float xOffset = 32; const float yOffset = 32;


	int tilecount = 0;

	for (auto element = tileData->FirstChild()->ToElement();
		element->NextSibling() != nullptr;
		element = element->NextSibling()->ToElement())
	{
		auto id = atoi(element->Attribute("gid"));
		if (id == Coin::s_ID) {
			coins.push_back(Coin(currentPos));
		}
		else if (id == PowerUpType::FIREBALL|| id == PowerUpType::BETTERJUMP) {
			powerUps.push_back(PowerUp(currentPos,PowerUpType(id)));
		}
		else if (id != 0) {
			tiles.push_back(Tile( 
				currentPos, 
				sf::Vector2f(xOffset, yOffset),
				imageFilepaths[id],
				id
				)
			);
		}
		
	
		if (tilecount % 250 == 0 && tilecount != 0) {
			currentPos.x = 0;
			currentPos.y += yOffset;
		}
		else {
			currentPos.x += xOffset;
		}
		tilecount++;
	}
	

}

Game::Level::Level(sf::Vector2f startSize,int levelID,sf::FloatRect renderArea) : checkArea(renderArea) ,LevelID(levelID)
{
	loadXml(levelID);		 
}

void Game::Level::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& coin : coins) {
		if(checkArea.contains(coin.getPosition()))
			coin.Draw(target, states);
	}
	for (auto& tile : tiles) {
		if (checkArea.contains(tile.getPosition()))
		tile.Draw(target, states);
	}
	for (auto& powerUp : powerUps) {
		if (checkArea.contains(powerUp.getPosition()))
			powerUp.Draw(target, states);
	}
}

void Game::Level::eraseCoin(int index)
{
   
	coins.erase(coins.begin() + index);
	
}
void Game::Level::erasePowerUp(int index) 
{
	powerUps.erase(powerUps.begin() + index);
}
