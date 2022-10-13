#pragma once

#include "Diamond.h"
#include <iostream>
//-------------------------------- CONSTRUCTOR ---------------------------------------
//Gets the location , icon and creates a Diamond.
Diamond::Diamond(sf::Vector2i location, char icon)
{
	sf::Texture* texture = Singleton::show().get_pic(17);
	m_pic.setTexture(*texture);
	m_pic.setScale(0.6, 0.6);
	m_icon = icon;
	m_pic_frame = 0;
	m_time_counter = 3;
	m_location.x = (float)location.x;
	m_location.y = (float)location.y;
}

//------------------------------- DRAW --------------------------------
//the draw funtion for Diamond.
void Diamond::draw(sf::RenderWindow& win, float clock_sample) 
{	
	m_time_counter--;
	if (m_time_counter == 0)
	{
		m_pic_frame = (m_pic_frame + SHAPE) % (10 * SHAPE);
		m_time_counter = 3;
	}
	m_pic.setTextureRect(sf::IntRect(m_pic_frame, 0, SHAPE, SHAPE));
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE);
	win.draw(m_pic);
}
