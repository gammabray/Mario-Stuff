#include "Character.hpp"
#include <iostream>


Game::Character::Character(const Vector2f& startPos, const Vector2f& startSize) 
	: AnimatedObject(startPos,startSize,6)
	,IsJumping(false), IsWalking(false),StartSpeed(0.2f,1.f)
//remember to add no of sprites later
{
	animationClock.restart();
	travelling = direction::STATIONARY;
	acceleration = Vector2f(0.f, 0.08f);
	if (!texture->loadFromFile("Images\\marioSpriteSheet.gif")) {
		texture.release();
		std::cout << "Failed to load Texture for Character..." << std::endl;
	}
	sprite->setTexture(*texture);
	sprite->setOrigin(startSize.x / 2, startSize.y / 2);
	addSprites();
	sprite->setTextureRect(SpriteStates[0]);
	sprite->setPosition(position);
	sprite->setScale(scaleFactor);
	IsVisible = true;

}


void Game::Character::addSprites()
{
	
	SpriteStates.push_back(sf::IntRect(3,0,13,17));
	SpriteStates.push_back(sf::IntRect(34,0,14,16));
	SpriteStates.push_back(sf::IntRect(66,0,12,17));
	SpriteStates.push_back(sf::IntRect(94,0,17,17));
	SpriteStates.push_back(sf::IntRect(SpriteStates[2]));
	SpriteStates.push_back(sf::IntRect(155,0,17,17));
}
void Game::Character::update(sf::View& v, sf::Keyboard::Key k)
{
	changeSprite();
	float delta = static_cast<float>( speedClock.restart().asMilliseconds());
	if (IsJumping) {
		this->move(delta, v);
	}
	if (k == sf::Keyboard::Up) {
		travelling = direction::UP;
		this->jump();

	}
	if (k == sf::Keyboard::Left)
	{
		sprite->setScale(-1, 1);
		travelling = direction::LEFT;
		velocity.x = StartSpeed.x;
		this->move(delta, v);

	}
	if (k == sf::Keyboard::Right)
	{
		sprite->setScale(1, 1);
		velocity.x = StartSpeed.x;
		travelling = direction::RIGHT;
		this->move(delta, v);

	}

	
	if(k == sf::Keyboard::Down){
		travelling = direction::DOWN;
	}
	if (k == sf::Keyboard::Unknown) {
		if (!IsJumping) {
			velocity.x = 0;
			travelling = direction::STATIONARY;
		}
	}
}
void Game::Character::jump()
{
	if (!IsJumping) {
		IsJumping = true;
		IsWalking = false;
		VelocityBeforeJumping = velocity;
		velocity.y = StartSpeed.y;
		
	}
	
}
void Game::Character::move(float delta, sf::View& v)
{
	
	switch (travelling) {
	case direction::LEFT:
		if (IsJumping) {
			return;
		}
		IsWalking = true;
		//v.move(delta * velocity.x, 0.f);
		this->sprite->move(delta * -velocity.x, 0.f);
		this->position += sf::Vector2f(delta * -velocity.x, 0.f);
		break;
	case direction::RIGHT:
		if (IsJumping) {
			return;
		}
		IsWalking = true;
		//v.move(delta * -velocity.x, 0.f);
		this->sprite->move(delta * velocity.x, 0.f);
		this->position += sf::Vector2f(delta * velocity.x, 0.f);
		break;
	case direction::UP:
		if (IsJumping) {
			if (this->position.y > 600) {
				this->position.y = 600;
				this->sprite->setPosition(sf::Vector2f(this->position.x,600));
				velocity = VelocityBeforeJumping;
				IsJumping = false;
				IsWalking = true;
				return;
			}
			velocity.y -= acceleration.y;
			//v.move(delta * VelocityBeforeJumping.x, 0);
			this->sprite->move(delta * VelocityBeforeJumping.x, delta * -velocity.y);
			this->position += sf::Vector2f(delta * VelocityBeforeJumping.x, delta * -velocity.y);
		}
		break;
	case direction::STATIONARY:
		velocity.x = 0;
		IsWalking = false;

		break;
	
		
	}
}

std::ostream& operator<<(std::ostream& o, const Vector2f& vec) {
	o << "x: " << vec.x << " y: " << vec.y;
	return o;
}

void Game::Character::DisplayInfo()

{
	std::cout << "position: " << this->position << std::endl << "velocity:" << this->velocity << std::endl;
}

void Game::Character::Draw(sf::RenderTarget & target, const sf::RenderStates & states)
{
	if(IsVisible)
		target.draw(*sprite,states.Default);
}

void Game::Character::changeSprite(int changeTo)
{
	if (this->travelling == direction::STATIONARY) {
		currSprite = 0;
		animationClock.restart();
	}
	
	else if(IsJumping) {
		currSprite = 5;
		animationClock.restart();
	}
	else {
		if (animationClock.getElapsedTime().asMilliseconds() >= 100) {
			currSprite++;
			if (currSprite > 4) {
				currSprite = 1;
			}
			animationClock.restart();
		}
		}
		
		
	sprite->setTextureRect(SpriteStates[currSprite]);

}
