#pragma once


#ifndef DISPLAYOBJECT_HPP
#define DISPLAYOBJECT_HPP


#include <SFML\Graphics.hpp>

using sf::Vector2f;

//Base class for all drawable objects in game
namespace Game {
	class DisplayObject {

	protected:
		Vector2f*      position;
		Vector2f*      size;
		Vector2f*      scaleFactor;
		sf::Texture*   texture;
		sf::Sprite*    sprite;
		sf::FloatRect* collisionBox;
		bool           IsVisible;
	public:
		const Vector2f& getPosition() { return *position; }
		void setPosition(const Vector2f& value) { *position = value; }
		const Vector2f& getSize() { return *size; }
		void setSize(const Vector2f& value) { *size = value; }
	    sf::Sprite getSprite() { return *sprite; }
		virtual void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) = 0;
		DisplayObject(const Vector2f& startPos, const Vector2f& startSize);
		virtual ~DisplayObject();



	};
}

#endif
