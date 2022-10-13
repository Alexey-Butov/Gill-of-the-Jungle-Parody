#pragma once

#include "PresentTime.h"
#include <iostream>


//will get the color , location , the icon and will create a PresentTime .
PresentTime::PresentTime(sf::Vector2i location, char icon) : m_time_counter(0)
{
	sf::Texture* texture = Singleton::show().get_pic(36);

	m_pic.setTexture(*texture);
	m_pic.setScale(0.6, 0.6);
	m_icon = icon;

	m_location.x = (float)location.x;
	m_location.y = (float)location.y;
}


//the draw funtion for PresentTime.
void PresentTime::draw(sf::RenderWindow& win, float clock_sample) 
{
	m_pic.setTextureRect(sf::IntRect(0, 0, SHAPE, SHAPE));
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE);
	win.draw(m_pic);
}