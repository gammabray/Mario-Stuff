#pragma once
#ifndef AABB_HPP
#define AABB_HPP
#include <SFML\Graphics.hpp>
namespace Game {
	class AABB //axis aligned bounding box for rectangular objects
	{
	public:
		AABB(sf::Vector2f s, sf::Vector2f pos);
		sf::Vector2f& getMinVector() { return mtv; }
		void setPosition(sf::Vector2f value) { position = value; }
		const bool IsColliding(AABB other);
		

	private:
		sf::Vector2f size,
			position,
			mtv;//minimum translation vector - if colliding, the vector to push object out of the other object
		float halfwidth,
			halfheight;
		const sf::Vector2f toUnitVector(const sf::Vector2f v);
		const float dotProduct(sf::Vector2f v1, sf::Vector2f v2) { return (v1.x * v2.x) + (v1.y * v2.y); }


	};
}
#endif