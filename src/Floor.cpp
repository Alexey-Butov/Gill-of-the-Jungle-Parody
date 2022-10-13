#pragma once

#include "Floor.h"
#include <iostream>

//-------------------------------- CONSTRUCTOR ---------------------------------------
//will get the location , the icon and will create a Floor.
Floor::Floor(sf::Vector2i location, char icon)
{
	sf::Texture* texture = Singleton::show().get_pic(5);

	m_pic.setTexture(*texture);

	m_icon = icon;

	m_location.x = (float)location.x;
	m_location.y = (float)location.y;
}

//------------------------------- DRAW --------------------------------
//the draw funtion for Floor.
void Floor::draw(sf::RenderWindow& win, float clock_sample) 
{
	m_pic.setTextureRect(sf::IntRect(0, 0, SHAPE, SHAPE));
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE );
	win.draw(m_pic);
}



