#pragma once

#include "Item.h"

class Apple : public Item 
{

public:

	//----Constructor for Apple object------
	Apple(sf::Vector2i location, char icon);

	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~Apple() = default;

private:
	int m_time_counter;
	int m_pic_frame;
};