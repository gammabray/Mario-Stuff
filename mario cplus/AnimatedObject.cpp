#include "AnimatedObject.hpp"

Game::AnimatedObject::AnimatedObject(const Vector2f & startPos, const Vector2f& startSize, int noOfSprites)
	: DisplayObject(startPos,startSize)
{
	_acceleration = new Vector2f();//add to later
	_deceleration = new Vector2f();
	_velocity =     new Vector2f();

}

Game::AnimatedObject::~AnimatedObject()
{
	
	delete _acceleration;
	delete _deceleration;
	delete _velocity;
}
