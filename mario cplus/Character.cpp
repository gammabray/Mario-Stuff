#include "Character.hpp"
#include <iostream>
#include "Enemy.hpp"
#include "Tile.hpp"




Game::Character::Character(const sf::Vector2f& startPos)
	: AnimatedObject(startPos, sf::Vector2f(24, 48), 6,sf::Vector2f(0.02f,0.08f),sf::Vector2f(0.3f,2.f)),
	IsJumping(false), IsWalking(false), StartSpeed(0.0f, 1.f), fallAcceleration(0.f, 0.08f), currentFallSpeed(0.f, 0.f)
{
	tracker = new PlayerTracker();
	animationClock.restart();
	travelling = direction::STATIONARY;
	
	if (!texture->loadFromFile("Images\\char.png")) {
		texture.release();//delete texture
		std::cout << "Failed to load Texture for Character..." << std::endl;
	}
	sprite->setTexture(*texture);
	addSprites();
	sprite->setTextureRect(SpriteStates[0]);//start standing
	sprite->setPosition(position);
	sprite->setScale(scaleFactor);
	
	IsMovable = true;

}

Game::Character::~Character()
{
	delete tracker;
}


void Game::Character::addSprites()
//Adds the location data of each sprite
{
	
	SpriteStates.push_back(sf::IntRect(0,0,24,48));//standing
	SpriteStates.push_back(sf::IntRect(33,0, 24, 48));//walk1 
	SpriteStates.push_back(sf::IntRect(66,0, 24, 48));//walk2
	SpriteStates.push_back(sf::IntRect(96,0, 24, 48));//walk3
	SpriteStates.push_back(sf::IntRect(SpriteStates[2]));//walk4
	SpriteStates.push_back(sf::IntRect(125,0, 24, 48));	//jump
	SpriteStates.push_back(sf::IntRect(163, 0, 24, 48));//dead
}
void Game::Character::update(Level& l)
//updates the position of the sprite on the screen
{

	changeSprite();
	float delta = static_cast<float>(speedClock.restart().asMilliseconds());//time since last frame
	tracker->trackTime();
	if (IsJumping) {
		this->move(delta, l);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->jump();
		travelling = direction::UP;


	}
	else {
		if (IsJumping) return;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (!IsWalking) {  //just started walking
				velocity.x = StartSpeed.x;
			}
			sprite->setScale(-1, 1);
			travelling = direction::LEFT;
			
			this->move(delta, l);
			return;


		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (!IsWalking) {  //just started walking
				velocity.x = StartSpeed.x;
			}
			sprite->setScale(1, 1);
			
			travelling = direction::RIGHT;
			this->move(delta, l);
			return;


		}
		
		
		else {
			travelling = direction::STATIONARY;
		}
		
	}
}
void Game::Character::jump()
//checks if the player is already jumping.
//if not, store the velocity before jumping
//and change the state of the object to jumping
{
	if (!IsJumping) {
		
		sprite->setPosition(this->getPosition().x, this->getPosition().y);
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
		directionBeforeJumping = travelling;
		IsJumping = true;
		IsWalking = false;
		
		velocity.y = StartSpeed.y;
		
	}
	
}

void Game::Character::move(float delta, Level& l)
//change the position of the player depending on whether
//they are jumping or not.
{
	sf::Vector2f oldPos = this->position;
	sf::Vector2f newPos = oldPos;
	if (IsWalking && velocity.x < maxVelocity.x) {
		velocity.x += acceleration.x;
	}
	
	switch (travelling) {
	case direction::LEFT:
		if (IsJumping) {
			return;
		}
		IsWalking = true;
		newPos += sf::Vector2f(delta * -velocity.x, 0.f);
		
		break;
	case direction::RIGHT:
		if (IsJumping) {
			return;
		}
		IsWalking = true;
		newPos += sf::Vector2f(delta * velocity.x, 0.f);
		
		break;
	case direction::UP:
		if (IsJumping) {
			
			velocity.y -= acceleration.y;

			newPos += sf::Vector2f(delta * VelocityBeforeJumping.x, delta * -velocity.y);

			
		}
		break;
	case direction::DOWN:

		if (!IsJumping) {
			currentFallSpeed.y += fallAcceleration.y;
			newPos.y += currentFallSpeed.y / 2;
		}
		break;
	case direction::STATIONARY:
		velocity = sf::Vector2f(0,0);
		currentFallSpeed = sf::Vector2f(0, 0);
		IsWalking = false;
		currSprite = 0;
		break;


	}
	collisionBox.setPosition(sprite->getPosition());
	
	if (this->collisionCheck(l)) {
		if (IsJumping) {
			velocity = directionBeforeJumping == direction::RIGHT? VelocityBeforeJumping : -VelocityBeforeJumping;
			if (VelocityBeforeJumping.x != 0.f) {
				this->IsWalking = true;
			}
			else {
				IsWalking = false;
			}
		}
		
		this->sprite->move(this->collisionBox.getMinVector());
		IsJumping = false;
	
		
	}
	else {
		sprite->setPosition(newPos);
		this->position = newPos;
	}
										 
	this->setPosition(sprite->getPosition());
	collisionBox.setPosition(sprite->getPosition());
	
	

}





void Game::Character::DisplayInfo()
//Shows where the character is on the screen
{
	std::cout << "position: " << this->position << std::endl << "velocity:" << this->velocity << std::endl;
}

void Game::Character::Draw(sf::RenderTarget & target, const sf::RenderStates & states)
//Draws the sprite onto the screen
{
	if(IsMovable)
		target.draw(*sprite,states.Default);
}

bool Game::Character::collisionCheck(Enemy & e)
//Checks for collision with an enemy
{
	return this->collisionBox.IsColliding(e.getCollisionBox());
} 

bool Game::Character::collisionCheck(Level & l)
//checks for collision between the coins and the player, and then the
//the tiles and they player. For coins the player is given score if they 
{
	for (int i = 0; i < l.getCoins().size(); i++) {
		if (this->collisionBox.IsColliding(l.getCoins()[i].getCollisionBox())) {
			l.eraseCoin(i);
			tracker->addScore(Coin::s_scoreGiven);
		}
	}
	
	for (Tile& t : l.getTiles()) {
		
		if (this->collisionBox.IsColliding(t.getCollisionBox())) {
			return true;
		}
		
	}
	return false;
}

void Game::Character::changeSprite(int changeTo)
//Changes what sprite is displayed
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
	
	t.setPosition(this->position.x, this->position.y - 200);
	rw.draw(*sprite);
	rw.draw(t);
	rw.display();
	
}
