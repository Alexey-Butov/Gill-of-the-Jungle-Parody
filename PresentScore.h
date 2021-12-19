#pragma once

#include "Present.h"

class PresentScore : public Present
{

public:

	//----Constructor for PresentScore object------
	PresentScore(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample); // draws the object on board
	void changPic()override {}; // changes the picture for animation
	sf::Sprite get_sprite()override { return m_pic; }; // gets picture
	void setLocation(float newState) {}; // sets objects location
	~PresentScore() = default;

private:

	int m_pic_frame;
	int m_time_counter;
};