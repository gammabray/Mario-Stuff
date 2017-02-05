#include "Character.hpp"
#include <iostream>
#include "Enemy.hpp"
#include "Tile.hpp"




Game::Character::Character(const sf::Vector2f& startPos)
	: AnimatedObject(startPos, sf::Vector2f(24, 48), 6,sf::Vector2f(0.02f,0.08f),sf::Vector2f(0.3f,2.f)),
	IsJumping(false), IsWalking(false) ,StartSpeed(0.4f, 1.f), fallAcceleration(0.f, 0.08f), currentFallSpeed(0.f, 0.f)
{
	CanFall = true;
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
	IsAccelerating = false;
	velocity.x = StartSpeed.x;
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
void Game::Character::Update(Level& l)
//updates the position of the sprite on the screen

{
	if (!respawnPointSet) {
		respawnPoint = l.respawnPoint;
		respawnPointSet = true;
	}
	if (IsDead) {
		
		sprite->setPosition(respawnPoint);
		this->position = sprite->getPosition();
		respawnPointSet = true;
		IsDead = false;
	}
	changeSprite();
	float delta = static_cast<float>(speedClock.restart().asMilliseconds());//time since last frame;
	tracker->trackTime();
	if (IsJumping) {
		this->fall(delta);
		this->Move(delta, l);
	}
	else if (CanFall) {
		this->fall(delta);
	}
	if (position.y > 1280) {
		this->Destroy();
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
			IsWalking = true;
			sprite->setScale(-1, 1);
			travelling = direction::LEFT;

			this->Move(delta, l);



		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (!IsWalking) {  //just started walking
				velocity.x = StartSpeed.x;
			}
			IsWalking = true;
			sprite->setScale(1, 1);

			travelling = direction::RIGHT;
			this->Move(delta, l);



		}
		else if (this->CanFall) {
			travelling = direction::STATIONARY;
			this->Move(delta, l);
		}


		else {
			travelling = direction::STATIONARY;
			velocity = sf::Vector2f(0, 0);
		}

	}
}


	
void Game::Character::jump()
//checks if the player is already jumping.
//if not, store the velocity before jumping
//and change the state of the object to jumping
{
	if (!IsJumping && !CanFall) {
		
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
		CanFall = false;
		acceleration.y = fallAcceleration.y;
		
		velocity.y = StartSpeed.y;
		
	}
	
}

void Game::Character::StopJump()
//stop the player jumping
{
	if (IsJumping) {
		velocity = directionBeforeJumping == direction::RIGHT ? VelocityBeforeJumping : -VelocityBeforeJumping;
		CanFall = false;
		if (VelocityBeforeJumping.x != 0.f) {
			this->IsWalking = true;
		}
		else {
			IsWalking = false;
		}
		IsJumping = false;
	}
}
void Game::Character::Move(float delta, Level& l)
//change the position of the player depending on whether
//they are jumping/faliing, or not.
{

	if (IsWalking && velocity.x < maxVelocity.x) {
		velocity.x += acceleration.x;
		IsAccelerating = true;
	}
	else {
		IsAccelerating = false;
	}

	switch (travelling) {
	case direction::LEFT:
		if (IsJumping || CanFall) {
			IsWalking = false;
			return;
		}
		
		sprite->move(delta * -velocity.x, 0);

		break;
	case direction::RIGHT:
		if (IsJumping || CanFall) {
			IsWalking = false;
			return;
		}
		
		sprite->move(delta * velocity.x, 0);

		break;
	case direction::UP:
		if (IsJumping) {
			velocity.y -= acceleration.y / 2;
			IsAccelerating = true;
			sprite->move(delta * VelocityBeforeJumping.x, delta * -velocity.y);
		}
		break;
	case direction::DOWN:



		break;
	case direction::STATIONARY:
		break;
		
	



	}

		
	


								 
	this->setPosition(sprite->getPosition());
	collisionBox.setPosition(sprite->getPosition());
	boundingBox = sprite->getGlobalBounds();
	
	

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

void Game::Character::Destroy()
{
	velocity = sf::Vector2f(0, 0);
	IsWalking = false;
	IsJumping = false;
	CanFall = true;
	tracker->removeLife();
	if (!tracker->AllLivesLost) {
		IsDead = true;
	}
	else {
		while (true) {

		}
	}


	
}

void Game::Character::fall(float delta)
{
	if (CanFall) {
		IsWalking = false;
		velocity.y += fallAcceleration.y;
		sprite->move(0, velocity.y);
		boundingBox = sprite->getGlobalBounds();
		position = sprite->getPosition();
	}

	
}
