#include "ScoreSaver.hpp"
#include "TinyXML\tinyxml2.h"
#include <iostream>
Game::ScoreSaver::ScoreSaver(PlayerTracker & tracker) : score(tracker.getScore()) , time(tracker.getTime())
{
	
	
}
bool Game::ScoreSaver::SaveScore(int currLevel)
{
	if (currLevel > 9) {
		throw "Invalid input exception: Level must be less than 9";
		return false;
	}
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError error = doc.LoadFile("Profiles\\profile.xml");
	if (error == tinyxml2::XMLError::XML_SUCCESS) {
		auto scoreInfo = doc.FirstChild()
			->NextSibling()
			->FirstChild()
			->FirstChild();
		
		for (int i = 0; i < currLevel; i++) {
			scoreInfo = scoreInfo->NextSibling();
		}
		if (std::stoi(scoreInfo->FirstChild()->Value()) < score ) {
			scoreInfo->FirstChild()->SetValue(std::to_string(this->score).c_str());
		}
			
		auto timeInfo = doc.FirstChild()
			->NextSibling()
			->FirstChild()
			->NextSibling()
			->FirstChild();
		for (int i = 0; i < currLevel; i++) {
			timeInfo = timeInfo->NextSibling();
		}
		if (std::stof(timeInfo->FirstChild()->Value()) > time.asMilliseconds() || std::stoi(timeInfo->FirstChild()->Value()) == 0) {
			timeInfo->FirstChild()->SetValue(std::to_string(time.asMilliseconds()).c_str());
		}

		
		auto error = doc.SaveFile("Profiles\\profile.xml");
		std::cout << error << std::endl;
		return true;
		
	}
	else {
		throw "Invalid filepath excpetion: File could not be loaded";

		return false;
	}
}

Game::ScoreSaver::~ScoreSaver()
{
}
