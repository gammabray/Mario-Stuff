#pragma once


#ifndef DISPLAYOBJECT_HPP
#define DISPLAYOBJECT_HPP
#include <SFML\Graphics.hpp>
#include <memory>

using sf::Vector2f;

namespace Game {
	class DisplayObject {
		///<summary>///
		/// Class: DisplayObject (Abstract)
		/// 
		///	The base class for all 'entities' in the game. This includes enemies and the character.
		///	It is not a base class for the Level and Background tiles as they are essentially containers for Level and Background Tiles.
		///
		///
		///
		///</summary>

	protected:
		Vector2f position;
		Vector2f size;
		Vector2f scaleFactor;
		std::unique_ptr<sf::Texture>  texture;
		std::unique_ptr<sf::Sprite>   sprite;
		sf::FloatRect collisionBox;
		bool           IsVisible;
	public:
		const Vector2f& getPosition() { return position; }
		void setPosition(const Vector2f& value) { position = value; }
		const Vector2f& getSize() { return size; }
		void setSize(const Vector2f& value) { size = value; }
		sf::Sprite getSprite() { return *sprite; }
		const sf::FloatRect& getCollisionBox() { return collisionBox; }
		DisplayObject(const DisplayObject& copy);
		virtual void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) = 0;//pure virtual function : implementation left to derived classes
		DisplayObject(const Vector2f& startPos, const Vector2f &startSize);
		virtual ~DisplayObject();//virtual destructor so called first



	};
}

#endif
