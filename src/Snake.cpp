#include "Snake.h"
#include <iostream>


//will get the location and icon and will create a monster.
Snake::Snake(sf::Vector2i location, char icon) : m_times(0), m_x(0)
{
	m_location.x = (float)location.x;
	m_location.y = (float)location.y;

	sf::Texture* texture = Singleton::show().get_pic(30); // set monsters picture.
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
void Snake::draw(sf::RenderWindow& win, float clock_sample)  // draws the frog object
{
	if (m_direction == right_t)
		from_y = SHAPE;
	else
		from_y = 0;
	change_pic = (change_pic + SHAPE) % (12 * SHAPE);
	m_pic.setTextureRect(sf::IntRect(change_pic, from_y, SHAPE, SHAPE)); // sprite sheet rectangle setting
	m_pic.setPosition(m_location.x * SHAPE, m_location.y * SHAPE); // fix position
	win.draw(m_pic);
}


//movement function.
//two different ways to move (smart , regular) .
//the smart use manhatten formula.
//the regular will randomize a direction.
void Snake::movement(float x, float y, float dirc) 
{
	float distance = x / 1000;
    m_x = distance; //for fix position after collide will save the fixed gap

	if (m_direction == right_t)
		m_location.x += distance;
	if (m_direction == left_t)
		m_location.x -= distance;
}

// update the move time counter.
void Snake::update_time_counter(float add) 
{
	m_time_counter += add;
}


// get vector2f for location and update the location.
void Snake::set_location(sf::Vector2f location)
{
	m_location = location;
}

// set the monster direction.
void Snake::set_direction()
{
	if (m_direction == left_t)
		m_direction = right_t;
	else
		m_direction = left_t;
}

// return the monster direction.
directions_t Snake::get_direction() const
{
	return m_direction;
}

// return the location.
const sf::Vector2f Snake::get_location() const
{
	return m_location;
}


void Snake::fix_position() 
{
	if (m_direction == right_t)
		m_location.x = m_location.x - m_x - 0.1;
	if (m_direction == left_t)
		m_location.x = m_location.x + m_x + 0.1;
}

void Snake::setScale()
{
	m_pic.setOrigin(0, SHAPE);
	m_pic.setScale(m_scale / m_times, m_scale / m_times);
	m_pic.setOrigin(0, 0);
}