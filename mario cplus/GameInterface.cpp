#include "GameInterface.hpp"

Game::GameInterface::GameInterface()
{
	font = std::make_unique<sf::Font>();
	if (!font->loadFromFile("C://Windows//Fonts//Arial.ttf")) {
		printf("Could not load font");
		fflush(stdout);
	}
	


	
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
	
	
	
}	

void Game::GameInterface::update(PlayerTracker & tracker,const sf::View& v)
{
	
	scoreLabel.setPosition(v.getCenter().x - 600,v.getCenter().y -360 );
	scoreValue.setPosition(v.getCenter().x - 500, v.getCenter().y - 360);
	scoreValue.setString(std::to_string(tracker.currScore));

	timeLabel.setPosition(v.getCenter().x + 400, v.getCenter().y - 360);
	timeValue.setPosition(v.getCenter().x + 500, v.getCenter().y - 360);
	timeValue.setString(tracker.timeSpent);


}

void Game::GameInterface::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(timeLabel);
	target.draw(timeValue);
	target.draw(scoreValue);
	target.draw(scoreLabel);
	

	
}
