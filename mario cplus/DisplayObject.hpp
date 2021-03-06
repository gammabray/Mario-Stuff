#pragma once


#ifndef DISPLAYOBJECT_HPP
#define DISPLAYOBJECT_HPP
#include <SFML\Graphics.hpp>
#include <memory>
#include "AABB.hpp"


namespace Game {
	class DisplayObject {
		///<summary>///
		/// Class: DisplayObject (Abstract)
		/// 
		///	The base class for all 'entities' in the game. This includes enemies and the character.
		///	It is not a base class for the Level and Background classes as they are essentially containers for Level and Background Tiles.
		///
		///
		///
		///</summary>

	protected:
		sf::Vector2f position;
		sf::Vector2f size;
		sf::Vector2f scaleFactor;
		std::unique_ptr<sf::Texture> texture;
		std::unique_ptr<sf::Sprite>  sprite;
		AABB collisionBox;
		
		bool IsMovable;
	public:
		sf::FloatRect boundingBox;
		const sf::Vector2f& getPosition() const { return position; } 
		void setPosition(const sf::Vector2f& value) { position = value; sprite->setPosition(position); }
		void setPosition(float x, float y) { position.x = x; position.y = y; sprite->setPosition(position); }
		const sf::Vector2f& getSize() { return size; }
		void setSize(const sf::Vector2f& value) { size = value; }
		sf::Sprite getSprite() const { return *sprite; }
		virtual void Draw(sf::RenderTarget& target,const sf::RenderStates& states = sf::RenderStates::Default ) const = 0;//pure virtual function : implementation left to derived classes
		DisplayObject(const sf::Vector2f& startPos, const sf::Vector2f &startSize);
		



	};
}

#endif
