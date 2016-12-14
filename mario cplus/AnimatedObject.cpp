#include "AnimatedObject.hpp"

Game::AnimatedObject::AnimatedObject(const Vector2f & startPos, const Vector2f& startSize, int noOfSprites)
	: DisplayObject(startPos,startSize)
{


}
std::ostream & Game::operator<<(std::ostream & o, sf::Vector2f v)
{
	o << "x: " << v.x << " y: " << v.y; return o;
}




