#pragma once
#ifndef POWERUP_HPP
#define POWERUP_HPP
#include "AnimatedObject.hpp"
#include "Character.hpp"
namespace Game {
	class Character;
	enum class PowerUpType {


	};
	class PowerUp : public AnimatedObject {
		bool IsColliding(Character& ch);
	};
}
#endif