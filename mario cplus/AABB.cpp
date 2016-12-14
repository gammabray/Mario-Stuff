#include "AABB.hpp"

Game::AABB::AABB(sf::Vector2f s, sf::Vector2f pos) : size(s), position(pos), halfheight(size.y / 2), halfwidth(size.x / 2), mtv(0, 0)
{

}

bool Game::AABB::IsColliding(AABB& other,bool jumping)
{
	

	sf::Vector2f lengthBetween((position.x) - (other.position.x), position.y - (other.position.y));
	
	if ((abs(lengthBetween.x) < halfwidth + other.halfwidth) && (abs(lengthBetween.y) < halfheight + other.halfheight)) {	//there is a collision
	
		if (lengthBetween.x == 0 || lengthBetween.y == 0) { mtv = sf::Vector2f(0, 0);  return true; }
		
		if (abs(lengthBetween.y) > abs(lengthBetween.x)) {
		
				mtv = sf::Vector2f(0, -lengthBetween.y - halfheight - other.halfheight);//top collision		
		}
		if (abs(lengthBetween.y) < abs(lengthBetween.x)) {
			if (lengthBetween.x < 0)
				mtv = sf::Vector2f(-lengthBetween.x - halfwidth - other.halfwidth, 0);
			else if (lengthBetween.x > 0)
				mtv = sf::Vector2f(-lengthBetween.x + halfwidth + other.halfwidth, 0);
		}
		
		if (jumping) {
			mtv = sf::Vector2f(0, -lengthBetween.y - halfheight - other.halfheight);
		}
		return true;
	}
	
	mtv = sf::Vector2f(0, 0);
	return false;

}

const sf::Vector2f Game::AABB::toUnitVector(const sf::Vector2f v)
{
	float mag = sqrtf((v.x * v.x) + (v.y * v.y));
	if (mag == 0) return v;
	return sf::Vector2f(v.x / mag, v.y / mag);
	
}
