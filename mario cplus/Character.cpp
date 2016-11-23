#include "Character.hpp"
#include <iostream>


Game::Character::Character(const Vector2f& startPos, const Vector2f& startSize) 
	: AnimatedObject(startPos,startSize,6)
	,IsJumping(false), IsWalking(false),StartSpeed(0.2f,1.f)

{
	animationClock.restart();
	travelling = direction::STATIONARY;
	acceleration = Vector2f(0.f, 0.08f);
	if (!texture->loadFromFile("Images\\marioSpriteSheet.gif")) {
		texture.release();//delete texture
		std::cout << "Failed to load Texture for Character..." << std::endl;
	}
	sprite->setTexture(*texture);
	sprite->setOrigin(startSize.x / 2, startSize.y / 2);//middle of character
	addSprites();
	sprite->setTextureRect(SpriteStates[0]);//start standing
	sprite->setPosition(position);
	sprite->setScale(scaleFactor);
	IsVisible = true;

}


void Game::Character::addSprites()
//Adds the location data of each sprite
{
	
	SpriteStates.push_back(sf::IntRect(3,0,13,17));
	SpriteStates.push_back(sf::IntRect(34,0,14,16));
	SpriteStates.push_back(sf::IntRect(66,0,12,17));
	SpriteStates.push_back(sf::IntRect(94,0,17,17));
	SpriteStates.push_back(sf::IntRect(SpriteStates[2]));
	SpriteStates.push_back(sf::IntRect(155,0,17,17));
	SpriteStates.push_back(sf::IntRect(187, 17, 15, 17));
}
void Game::Character::update(sf::View& v)
//updates the position of the sprite on the screen
{
	changeSprite();
	float delta = static_cast<float>( speedClock.restart().asMilliseconds());//time since last frame
	collisionBox = sprite->getGlobalBounds();//set collision box
	if (IsJumping) {
		this->move(delta, v);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->jump();
		travelling = direction::UP;
		

	}
	else {
		if (IsJumping) return;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite->setScale(-1, 1);
			travelling = direction::LEFT;
			velocity.x = StartSpeed.x;
			this->move(delta, v);
			return;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite->setScale(1, 1);
			velocity.x = StartSpeed.x;
			travelling = direction::RIGHT;
			this->move(delta, v);
			return;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			travelling = direction::DOWN;
			return;
		}
		travelling = direction::STATIONARY;
	}
}
void Game::Character::jump()
//checks if the player is already jumping.
//if not, store the velocity before jumping
//and change the state of the object to jumping
{
	if (!IsJumping) {
		switch (travelling) {
		case direction::LEFT:
			VelocityBeforeJumping.x = -velocity.x;
			break;
		case direction::RIGHT:
			VelocityBeforeJumping.x = velocity.x;
			break;
		default:
			VelocityBeforeJumping.x = 0;
			break;
		}
		IsJumping = true;
		IsWalking = false;
		
		velocity.y = StartSpeed.y;
		
	}
	
}
void Game::Character::move(float delta, sf::View& v)
//change the position of the player depending on whether
//they are jumping or not.
{
	
	switch (travelling) {
	case direction::LEFT:
		if (IsJumping) {
			return;
		}
		IsWalking = true;
		v.move(delta * -velocity.x, 0.f);
		this->sprite->move(delta * -velocity.x, 0.f);
		this->position += sf::Vector2f(delta * -velocity.x, 0.f);
		break;
	case direction::RIGHT:
		if (IsJumping) {
			return;
		}
		IsWalking = true;
		v.move(delta * velocity.x, 0.f);
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
				IsWalking = false;
				return;
			}
			velocity.y -= acceleration.y;
			v.move(delta * VelocityBeforeJumping.x, 0);
			this->sprite->move(delta * VelocityBeforeJumping.x, delta * -velocity.y);
			
			this->position += sf::Vector2f(delta * VelocityBeforeJumping.x, delta * -velocity.y);
		}
		break;
	case direction::STATIONARY:
		velocity.x = 0;
		IsWalking = false;
		currSprite = 0;
		break;
	
		
	}
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
	
	if (!IsJumping && !IsWalking) {
		currSprite = 0;
	}
	else if(IsJumping) {
		currSprite = 5;
		animationClock.restart();
	}
	else if(IsWalking) {
		if (animationClock.getElapsedTime().asMilliseconds() >= 100) {
			currSprite++;
			if (currSprite > 4) {
				currSprite = 1;
			}
			animationClock.restart();
		}
	}
	else {
		currSprite = 0;
	}
		
		
	sprite->setTextureRect(SpriteStates[currSprite]);

}

void Game::Character::hit(sf::RenderWindow& rw)
{
	currSprite = 6;
	sprite->setTextureRect(SpriteStates[currSprite]);
	sf::Font f;
	f.loadFromFile("C://Windows//Fonts//Arial.ttf");
	
	sf::Text t("you lost", f, 40u);
	t.setFillColor(sf::Color::White);
	t.setPosition(this->position.x, this->position.y - 200);
	rw.draw(*sprite);
	rw.draw(t);
	rw.display();
	
}
