#include "AABB.hpp"

Game::AABB::AABB(sf::Vector2f s, sf::Vector2f pos) : size(s), position(pos), halfheight(size.y / 2), halfwidth(size.x / 2), mtv(0, 0)
{

}

const bool Game::AABB::IsColliding(AABB other)
{
	std::vector<sf::Vector2f> axes{ toUnitVector(sf::Vector2f(1,0)),toUnitVector(sf::Vector2f(0,1)) };
	axes.shrink_to_fit();

	sf::Vector2f lengthBetween((position.x + (size.x / 2)) - (other.position.x + (other.size.x / 2)), (position.y + (size.y / 2)) - (other.position.y + (other.size.y / 2)));
	if ((abs(lengthBetween.x) < halfwidth + other.halfwidth) && (abs(lengthBetween.y) < halfheight + other.halfheight)) {
		mtv = sf::Vector2f(abs(lengthBetween.x) - halfwidth - other.halfwidth, abs(lengthBetween.y) - halfheight - other.halfheight);
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
