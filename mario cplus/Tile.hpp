#pragma once
#ifndef TILE_HPP
#define TILE_HPP
#include <SFML\Graphics.hpp>
#include <memory>
#include "DisplayObject.hpp"
namespace Game {
	enum tileID : char {

		DIRT = '1',
		SNOW,   // 2
		SAND,   // 3
		METAL,// 4
		DLTOP,// 5
		DRTOP,// 6
		DLBOT,// 7
		DRBOT,// 8
		DLEDGE = 'G', 
		DREDGE, //H
		DTEDGE, //I
		DBEDGE, //J
		DMIDDLE, //K
		POWERUP = 'P',
		CHECKPOLE = 'C',
		CHECKFLAG = 'D',
		FINISHFLAG = 'F',
		

	};
	class Tile : public DisplayObject
		///<summary>
		///Class : Tile
		///
		///A class for each tile (Each bit of the level). Solely used by
		///the Level class to draw multiple tiles with one call of draw. 
		///</summary>

	{
	protected:
		
	public:
		
		tileID ID;		
		void Draw(sf::RenderTarget & target,const sf::RenderStates & states) const;

		Tile(const sf::Vector2f & startPos, const sf::Vector2f & startSize, std::string location, int ID);

		
		
		
	

	};
}

#endif