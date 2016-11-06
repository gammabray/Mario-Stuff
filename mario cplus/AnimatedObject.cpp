#include "AnimatedObject.hpp"

Game::AnimatedObject::AnimatedObject(const Vector2f & startPos, const Vector2f& startSize, int noOfSprites)
	: DisplayObject(startPos,startSize)
{
	acceleration = new Vector2f();//add to later
	deceleration = new Vector2f();
	velocity =     new Vector2f();

}

Game::AnimatedObject::~AnimatedObject()
{
	
	delete acceleration;
	delete deceleration;
	delete velocity;
}
