#include "BadGuy.hpp"



Game::BadGuy::BadGuy(const sf::Vector2f& startPos)
	: Enemy(startPos,sf::Vector2f(24,24),sf::Vector2f(0.15f,0.f),EnemyType::BADGUY)
	,colFlag(false)
{
	currSprite = 0;
	CanFall = true;
	addSprites();
	colFlag = false;
	
	speedClock.restart();
	velocity.y = 0;
}



void Game::BadGuy::update(Character& ch)
{
	

	float delta = static_cast<float>(speedClock.restart().asMilliseconds());
	fall();
	move(delta, ch);
	boundingBox = sprite->getGlobalBounds();
	sprite->setTextureRect(SpriteStates[currSprite]);
}
void Game::BadGuy::move(float delta, Character &ch) {
	

		if (this->position.x == ch.getPosition().x) {
			colFlag = true;
			return;
		}
		if (this->position.x > ch.getPosition().x && !colFlag) {
			sprite->move(-startSpeed.x * delta, 0);



		}
		else if (this->position.x < ch.getPosition().x && !colFlag) {
			sprite->move(startSpeed.x * delta, 0);
		

		}
		this->position = sprite->getPosition();
		colFlag = false;





}

void Game::BadGuy::addSprites()
{
	SpriteStates.push_back(sf::IntRect(0, 0, 24, 24));
}

void Game::BadGuy::Draw(sf::RenderTarget & target, const sf::RenderStates & states) const
{
	target.draw(*sprite, states.Default);
}

void Game::BadGuy::fall() {
	if (CanFall) {
		IsWalking = false;
		velocity.y += acceleration.y;
		sprite->move(0, velocity.y);
		boundingBox = sprite->getGlobalBounds();
		position = sprite->getPosition();
	}
	else {
		IsWalking = true;
	}

}




