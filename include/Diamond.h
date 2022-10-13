#pragma once

#include "Item.h"

class Diamond : public Item
{

public:

	//----Constructor for Diamond------
	Diamond(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~Diamond() = default;

private:

	int m_pic_frame;
	int m_time_counter;
};


