#pragma once

#include "Present.h"

class PresentTime : public Present
{

public:

	//----Constructor for PresentTime object------
	PresentTime(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample)  ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~PresentTime() = default;

private:

	int m_pic_frame;
	int m_time_counter;
};