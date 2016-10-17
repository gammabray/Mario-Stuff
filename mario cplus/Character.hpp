#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AnimatedObject.hpp"
#include <SFML\Graphics.hpp>
using sf::Vector2f;

//Represents the player's character in the game
namespace Game {
	class Character : public AnimatedObject
	{
	protected:
		bool       IsWalking;
		bool       IsJumping;
		Vector2f* _VelocityBeforeJumping;

	public:
		Character(const Vector2f& startPos, const Vector2f& startSize);
		void addSprites();
		void move(float delta, const sf::View& v);
		void update(const sf::View& v, sf::Keyboard::Key k = sf::Keyboard::Key::Unknown);
		void DisplayInfo();
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states);




	};
}

#endif