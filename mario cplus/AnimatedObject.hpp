#pragma once

#ifndef ANIMATEDOBJECT_HPP
#define ANIMATEDOBJECT_HPP
#include "DisplayObject.hpp"
#include "SFML\Graphics.hpp"
#include <vector>

using sf::Vector2f;
class AnimatedObject : public DisplayObject {
protected:
	std::vector<sf::IntRect> SpriteStates;
	enum class direction {	
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	direction travelling;
	int       currSprite;
	sf::Clock _animationClock;
	sf::Clock _speedClock;
	Vector2f* _acceleration;
	Vector2f* _deceleration;
	Vector2f* _velocity;
public:
	virtual void addSprites() = 0;
	virtual void move(float delta, const sf::View&v) = 0;
	virtual void update(const sf::View& v, sf::Keyboard::Key k = sf::Keyboard::Key::Unknown) = 0;
	virtual void DisplayInfo() = 0;

	
	AnimatedObject(const Vector2f& startPos, const Vector2f& startSize, int noOfSprites);
	~AnimatedObject();
};
#endif