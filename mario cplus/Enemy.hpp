#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "AnimatedObject.hpp"
namespace Game {
	class Enemy : public AnimatedObject
	{
	private:
		std::string name;


	public:
		Enemy();
		~Enemy();
	};
}
#endif



