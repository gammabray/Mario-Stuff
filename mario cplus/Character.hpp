#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AnimatedObject.hpp"
#include <SFML\Graphics.hpp>
using sf::Vector2f;


namespace Game {
	class Character : public AnimatedObject
	{
		///<summary>
		///Class: Character
		///
		///The class that represents the player in the game.
		///
		///</summary>
	protected:
		
		Vector2f VelocityBeforeJumping;//what the players velocity was before the jump function was executed
		const Vector2f StartSpeed;//original speed when starting to move
		

	public:
		bool IsWalking;
		bool IsJumping;
		Character(const Vector2f& startPos, const Vector2f& startSize);
		void addSprites();
		void move(float delta, sf::View& v);//move character and view according to speed, whether player is jumping
		void update(sf::View& v);//Update position of character on screen
		void jump();//Initiate jumping
		void DisplayInfo();
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default);
		void changeSprite(int changeTo = 0);//change what sprite is displayed
		void hit(sf::RenderWindow& rw);//when hit by enemy



	};
}

#endif