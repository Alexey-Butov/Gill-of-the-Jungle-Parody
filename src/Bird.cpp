#include "Bird.h"
#include <iostream>


//will get the location and icon and will create a monster.
Bird::Bird(sf::Vector2i location, char icon)
{
	m_location.x = (float)location.x;
	m_location.y = (float)location.y;

	sf::Texture* texture = Singleton::show().get_pic(28); // set monsters picture.
	m_pic.setTexture(*texture);

	m_icon = icon; //set icon.
	m_speed = 1; //default speed.
	from_y = 0;
	from_x = 0;
	change_pic = 0;
	m_direction = left_t; //default direction.
	m_time_counter = 0;
}


// draw function.
void Bird::draw(sf::RenderWindow& win, float clock_sample)  // draws the Bird object
{
	if (m_direction == right_t)
		from_y = 0;
	else
		from_y = SHAPE;
	change_pic = (change_pic + SHAPE) % (9 * SHAPE);
	m_pic.setTextureRect(sf::IntRect(change_pic, from_y, SHAPE, SHAPE)); // sprite sheet rectangle setting
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE); //fix position
	win.draw(m_pic);
}


//movement function.
void Bird::movement(float x, float clock_sample, float y) 
{
	directions_t dirc = stand_t;
	float distance = x / 500;//speed handle
	int floorHeight = 9;
	m_x = distance;
	m_y = distance;

	int num = rand() % 30;
	if (num % 2 == 0)
	{
		if (x > m_location.x)
			dirc = right_t;
		if (x < m_location.x)
			dirc = left_t;
		if (x == m_location.x)
		{
			if (y > m_location.y)
				dirc = down_t;
			if (y < m_location.y)
				dirc = up_t;
		}
	}
	else
	{
		if (y > m_location.y)
			dirc = down_t;
		if (y < m_location.y)
			dirc = up_t;
		if (y == m_location.y)
		{
			if (x > m_location.x)
				dirc = right_t;
			if (x < m_location.x)
				dirc = left_t;
		}
	}
	if (dirc == up_t)
		m_location.y = m_location.y - distance;
	if (dirc == down_t && (m_location.y + distance) < floorHeight)
		m_location.y = m_location.y + distance;
	if (dirc == right_t)
	{
		m_location.x = m_location.x + distance;
		m_direction = dirc;
	}
	if (dirc == left_t)
	{
		m_location.x = m_location.x - distance;
		m_direction = dirc;
	}	
}

// update the move time counter.
void Bird::update_time_counter(float add) 
{
	m_time_counter += add;
}


// get vector2f for location and update the location.
void Bird::set_location(sf::Vector2f location) 
{
	m_location = location;
}

// set the monster direction.
void Bird::set_direction() 
{
	if (m_direction == left_t)
		m_direction = right_t;
	else if (m_direction == right_t)
		m_direction = left_t;
	else if (m_direction == up_t)
		m_direction = down_t;
	else
		m_direction = up_t;
}

// return the monster direction.
directions_t Bird::get_direction() const
{
	return m_direction;
}

// return the location.
const sf::Vector2f Bird::get_location() const
{
	return m_location;
}


void Bird::fix_position() 
{
	if (m_direction == right_t)
		m_location.x = m_location.x - m_x - 0.1;
	if (m_direction == left_t)
		m_location.x = m_location.x + m_x + 0.1;
	if (m_direction == up_t)
		m_location.y = m_location.y + m_y + 0.1;
	if (m_direction == down_t)
		m_location.y = m_location.y - m_y - 0.1;
	for (int i = 0; i < 4; i++)
		m_location.y -= 0.05;
}
