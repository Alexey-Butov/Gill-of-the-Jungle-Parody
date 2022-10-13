#pragma once

#include "KeyGate.h"
#include <iostream>

/////////////////////// CONSTRUCTOR //////////////////////////////////
//will get the location , the icon and will create a KeyGate.
KeyGate::KeyGate(sf::Vector2i location, char icon):m_open(false)
{
	sf::Texture* texture = Singleton::show().get_pic(12);
	m_pic.setTexture(*texture);
	sf::Texture* texture2 = Singleton::show().get_pic(20);
	m_openDoor.setTexture(*texture2);

	m_icon = icon;

	m_location.x = (float)location.x;
	m_location.y = (float)location.y;
}

//---------------------------- DRAW ------------------------------
//the draw funtion for KeyGate.
void KeyGate::draw(sf::RenderWindow& win, float clock_sample) 
{
	//std::cout << m_open << std::endl;
	if(!m_open)
	{
		m_pic.setTextureRect(sf::IntRect(0, 0, SHAPE, SHAPE));
		m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE);
		win.draw(m_pic);
	}
	else if(m_open)
	{
		m_openDoor.setTextureRect(sf::IntRect(0, 0, SHAPE, SHAPE));
		m_openDoor.setPosition(m_location.x * SHAPE, m_location.y * SHAPE);
		win.draw(m_openDoor);
	}
}

//sets pic change
void KeyGate::changPic() 
{
	if(m_open)
		m_open = false;
	else
		m_open = true;
}



