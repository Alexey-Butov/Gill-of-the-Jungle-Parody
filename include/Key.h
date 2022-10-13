#pragma once

#include "Item.h"

class Key : public Item
{

public:

	//----Constructor for key object------
	Key(sf::Vector2i location, char icon) ;
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~Key() = default;

private:

	int m_pic_frame;
	int m_time_counter;
};