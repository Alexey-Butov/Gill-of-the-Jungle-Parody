#pragma once

#include <iostream>
#include "Apple.h"


//------------------------------------- CONSTRUCTOR -----------------------------------
//will get the color , location , the icon and will create a Apple .
Apple::Apple(sf::Vector2i location, char icon)
{
	sf::Texture* texture = Singleton::show().get_pic(9);

	m_pic.setTexture(*texture);
	m_pic_frame = 0;
	m_pic.setScale(0.4, 0.4);
	m_icon = icon;
	m_time_counter = 3;
	m_location.x = (float)location.x;
	m_location.y = (float)location.y;
}

//--------------------------- DRAW -----------------------------
//the draw funtion for Apple object.
void Apple::draw(sf::RenderWindow& win, float clock_sample)
{
	m_time_counter--;
	if (m_time_counter == 0)
	{
		m_pic_frame = (m_pic_frame + SHAPE) % (20 * SHAPE);
		m_time_counter = 3;
	}
	m_pic.setTextureRect(sf::IntRect(m_pic_frame, 0, SHAPE, SHAPE));
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE);
	win.draw(m_pic);
}



