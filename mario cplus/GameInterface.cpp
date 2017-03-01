#include "GameInterface.hpp"
#include <iostream>




Game::GameInterface::GameInterface() : hasWon(false)
{
	font = std::make_unique<sf::Font>();
	keyTexture = std::make_unique<sf::Texture>();
	if (!keyTexture->loadFromFile("Images\\Interface\\zkey.png")) {
		std::cout << "Could not load Z key image for power-up" << std::endl;
	}
	if (!font->loadFromFile("C://Windows//Fonts//Arial.ttf")) {
		std::cout << "Could not load font" << std::endl;
		
	}
	keySprite.setTexture(*keyTexture);
	


	
	scoreLabel.setString("Score:");
	scoreLabel.setFont(*font);
	scoreLabel.setFillColor(sf::Color::White);
	scoreLabel.setCharacterSize(32);


	scoreValue.setString("");
	scoreValue.setFont(*font);
	scoreValue.setFillColor(sf::Color::White);
	scoreValue.setCharacterSize(32);  	
	
	
	timeLabel.setString("Time: ");
	timeLabel.setFont(*font);
	timeLabel.setFillColor(sf::Color::White);
	timeLabel.setCharacterSize(32);

	timeValue.setString("");
	timeValue.setFont(*font);
	timeValue.setFillColor(sf::Color::White);
	timeValue.setCharacterSize(32);

	lifeLabel.setString("Lives: ");
	lifeLabel.setFont(*font);
	lifeLabel.setFillColor(sf::Color::White);
	lifeLabel.setCharacterSize(32);

	lifeValue.setString("");
	lifeValue.setFont(*font);
	lifeValue.setFillColor(sf::Color::White);
	lifeValue.setCharacterSize(32);

	wonLabel.setString("You beat the level");
	wonLabel.setFont(*font);
	wonLabel.setFillColor(sf::Color::White);
	wonLabel.setCharacterSize(32);

	powerUpLabel.setString("Current Power-up:");
	powerUpLabel.setFont(*font);
	powerUpLabel.setFillColor(sf::Color::Cyan);
	powerUpLabel.setCharacterSize(32);

	powerUpValue.setString("None");
	powerUpValue.setFont(*font);
	powerUpValue.setFillColor(sf::Color::White);
	powerUpValue.setCharacterSize(32);

	

	
	
	
}	

void Game::GameInterface::update(PlayerTracker & tracker,const sf::View& v)
{
	
	scoreLabel.setPosition(v.getCenter().x - 600,v.getCenter().y - 360);
	scoreValue.setPosition(v.getCenter().x - 500, v.getCenter().y - 360);
	scoreValue.setString(std::to_string(tracker.currScore));

	timeLabel.setPosition(v.getCenter().x + 380, v.getCenter().y - 360);
	timeValue.setPosition(v.getCenter().x + 480, v.getCenter().y - 360);
	timeValue.setString(convertToStandardTime(tracker.timeSpent));

	lifeLabel.setPosition(v.getCenter().x + 400, v.getCenter().y + 300);
	lifeValue.setPosition(v.getCenter().x + 500, v.getCenter().y + 300);
	lifeValue.setString(std::to_string(tracker.currLives));

	powerUpLabel.setPosition(v.getCenter().x - 600, v.getCenter().y + 300);
	powerUpValue.setPosition(v.getCenter().x - 320, v.getCenter().y + 300);

	keySprite.setPosition(v.getCenter().x - 200, v.getCenter().y + 300);
	
	switch (tracker.currPowerUp)
	{
	case PowerUpType::BETTERJUMP:
		powerUpValue.setString("Higher jump");
		powerUpValue.setFillColor(sf::Color::Green);
		DrawKey = false;
		break;
	case PowerUpType::FIREBALL:
		powerUpValue.setString("Fireball");		
		powerUpValue.setFillColor(sf::Color::Red);
		DrawKey = true;
		break;
	default:
		powerUpValue.setString("None");
		powerUpValue.setFillColor(sf::Color::White);
		DrawKey = false;
		break;
	}

	hasWon = tracker.GameCompleted;
	if (hasWon) {
		wonLabel.setPosition(v.getCenter());
	}

}

void Game::GameInterface::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(timeLabel);
	target.draw(timeValue);
	target.draw(scoreValue);
	target.draw(scoreLabel);
	target.draw(lifeValue);
	target.draw(lifeLabel);
	target.draw(powerUpLabel);
	target.draw(powerUpValue);
	if (DrawKey) {
		target.draw(keySprite);
	}
	
	if (hasWon) {
		target.draw(wonLabel);
	}
	
	

	
}

std::string Game::GameInterface::convertToStandardTime(sf::Time & t) //convert to min:second:ms
{
	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << static_cast<int>(t.asSeconds() / 60) << ":";//minutes
	ss << std::setfill('0') << std::setw(2) << static_cast<int>(t.asSeconds() - static_cast<int>(t.asSeconds() / 60) * 60) << ":";//seconds
	ss << std::setfill('0') << std::setprecision(3) << t.asMilliseconds() - static_cast<int>(t.asSeconds()) * 1000; //milliseconds
	return ss.str();
	
}
