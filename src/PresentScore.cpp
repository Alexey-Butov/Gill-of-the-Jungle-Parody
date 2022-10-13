#pragma once

#include "PresentScore.h"
#include <iostream>


//will get the location , the icon and will create a PresentScore.
PresentScore::PresentScore(sf::Vector2i location, char icon)
{
	sf::Texture* texture = Singleton::show().get_pic(35);

	m_pic.setTexture(*texture);
	m_pic.setScale(0.6, 0.6);
	m_icon = icon;

	m_location.x = (float)location.x;
	m_location.y = (float)location.y;
}


//the draw funtion for PresentScore.
void PresentScore::draw(sf::RenderWindow& win, float clock_sample) 
{
	m_pic.setTextureRect(sf::IntRect(0, 0, SHAPE, SHAPE));
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE);
	win.draw(m_pic);
}



