#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AnimatedObject.hpp"
#include <SFML\Graphics.hpp>
using sf::Vector2f;


namespace Game {
	class Character : public AnimatedObject
	{
		//Represents the player's character in the game
	protected:
		
		Vector2f* _VelocityBeforeJumping;
		const Vector2f StartSpeed;

	public:
		bool       IsWalking;
		bool       IsJumping;
		Character(const Vector2f& startPos, const Vector2f& startSize);
		void addSprites();
		void move(float delta, sf::View& v);
		void update(sf::View& v, sf::Keyboard::Key k = sf::Keyboard::Key::Unknown);
		void DisplayInfo();
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default);




	};
}

#endif