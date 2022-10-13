#pragma once

#include "Present.h"

class PresentScore : public Present
{

public:

	//----Constructor for PresentScore object------
	PresentScore(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample)  ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~PresentScore() = default;

private:

	int m_pic_frame;
	int m_time_counter;
};