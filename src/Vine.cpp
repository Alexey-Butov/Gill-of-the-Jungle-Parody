#pragma once

#include "Vine.h"
#include <iostream>

//----------------------------- CONSTRUCTOR --------------------------------
//will get the color , location , the icon and will create a Vine.
Vine::Vine(sf::Vector2i location, char icon)
{
	sf::Texture* texture = Singleton::show().get_pic(15);

	m_pic.setTexture(*texture);

	m_icon = icon;

	m_location.x = (float)location.x;
	m_location.y = (float)location.y;
}

//--------------------------- DRAW -----------------------------------
//the draw funtion for Vine.
void Vine::draw(sf::RenderWindow& win, float clock_sample) 
{
	m_pic.setTextureRect(sf::IntRect(0, 0, SHAPE, SHAPE));
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE);
	win.draw(m_pic);
}



