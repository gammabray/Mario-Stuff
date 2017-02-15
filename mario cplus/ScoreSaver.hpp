#pragma once
#ifndef SCORESAVER_HPP
#define SCORESAVER_HPP
#import <C:\\Program Files (x86)\\Common Files\\System\\ado\\msado15.dll> rename( "EOF", "AdoNSEOF" )
#include "PlayerTracker.hpp"
namespace Game {
	class ScoreSaver
	{
	public:
		ScoreSaver(PlayerTracker & tracker);
		~ScoreSaver();
	};
}

#endif 



