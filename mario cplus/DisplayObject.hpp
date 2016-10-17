#pragma once


#ifndef DISPLAYOBJECT_HPP
#define DISPLAYOBJECT_HPP


#include <SFML\Graphics.hpp>
using sf::Vector2f;

//Base class for all drawable objects in game
namespace Game {
	class DisplayObject {

	protected:
		Vector2f*      _position;
		Vector2f*      _size;
		Vector2f*      _scaleFactor;
		sf::Texture*   _texture;
		sf::Sprite*    _sprite;
		sf::FloatRect* _collisionBox;
		bool           IsVisible;
	public:
		const Vector2f getPosition() { return *_position; }
		void setPosition(const Vector2f& value) { *_position = value; }
		const Vector2f getSize() { return *_size; }
		void setSize(const Vector2f& value) { *_size = value; }
	    sf::Sprite getSprite() { return *_sprite; }
		virtual void Draw(sf::RenderTarget& target, const sf::RenderStates& states) = 0;
		DisplayObject(const Vector2f& startPos, const Vector2f& startSize);
		~DisplayObject();



	};
}

#endif
