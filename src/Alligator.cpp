#pragma once

#include "Alligator.h"
#include <iostream>


//will get the location and icon and will create a monster.
Alligator::Alligator(sf::Vector2i location, char icon): m_x(0)
{
	m_location.x = (float)location.x;
	m_location.y = (float)location.y;

	sf::Texture* texture = Singleton::show().get_pic(24); // set monsters picture.
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
void Alligator::draw(sf::RenderWindow& win, float clock_sample)  // draws the Alligator object
{
	if (m_direction == right_t)
		from_y = 0;
	else
		from_y = SHAPE;
	change_pic = (change_pic + SHAPE) % (10 * SHAPE);
	m_pic.setTextureRect(sf::IntRect(change_pic, from_y, SHAPE, SHAPE)); // sprite sheet rectangle setting
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE); //fix position
	win.draw(m_pic);
}


//movement function.
void Alligator::movement(float x, float y, float dirc) 
{
	float distance = x / 1000;
	m_x = distance;

	if (m_direction == right_t)
		m_location.x += distance;
	if (m_direction == left_t)
		m_location.x -= distance;
}

// update the move time counter.
void Alligator::update_time_counter(float add) 
{
	m_time_counter += add;
}


// get vector2f for location and update the location.
void Alligator::set_location(sf::Vector2f location) 
{
	m_location = location;
}

// set the monster direction.
void Alligator::set_direction()
{
	if (m_direction == left_t)
		m_direction = right_t;
	else
		m_direction = left_t;
}

// return the monster direction.
directions_t Alligator::get_direction() const
{
	return m_direction;
}

// return the location.
sf::Vector2f Alligator::get_location() const
{
	return m_location;
}


void Alligator::fix_position() 
{
	if (m_direction == right_t)
		m_location.x = m_location.x - m_x - 0.1;
	if (m_direction == left_t)
		m_location.x = m_location.x + m_x + 0.1;
}
