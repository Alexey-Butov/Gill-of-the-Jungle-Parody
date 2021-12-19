#pragma once

#include "Present.h"

class PresentShield : public Present
{

public:

	//----Constructor for PresentShield object------
	PresentShield(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample); // draws the object on board
	void changPic()override {}; // changes the picture for animation
	sf::Sprite get_sprite()override { return m_pic; }; // gets picture
	void setLocation(float newState) {}; // sets objects location
	~PresentShield() = default;

private:

	int m_pic_frame;
	int m_time_counter;
};