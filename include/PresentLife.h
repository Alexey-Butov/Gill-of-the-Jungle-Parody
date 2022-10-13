#pragma once

#include "Present.h"

class PresentLife : public Present
{

public:

	//----Constructor for PresentLife object------
	PresentLife(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~PresentLife() = default;

private:

	int m_pic_frame;
	int m_time_counter;
};