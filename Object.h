#pragma once

#include <SFML\Graphics.hpp>
#include "Singleton.h"

constexpr float HEIGHT = 30, WIDTH = 30, TO_CENTER = 48;
constexpr int SHAPE = 96;

class Object
{

public:

	//----Constructor for object base------
	Object();
	virtual ~Object() = default; // destructor
	virtual void draw(sf::RenderWindow& window, float clock_sample) = 0; // virtual draw func
	virtual sf::Sprite get_sprite() = 0; // virtual get picture func
	virtual void setLocation(float newState) = 0;

protected:

	char m_icon; // icon char
	sf::Sprite m_pic; // sprite pic
	sf::Color m_color; // color
	sf::Vector2f m_location; // location
	float m_width; 
	float m_length;
	sf::Vector2f m_position;
};