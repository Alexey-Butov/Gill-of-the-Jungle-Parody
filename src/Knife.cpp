#pragma once

#include "Knife.h"

//c-tor
Knife::Knife(Player& p)
{
	set_pos(p);
	setknife();
}

//sets knife movement
void Knife::move(float x, float y, float dirc) 
{
	if (m_dirc == 2)
		m_knife_pos.x += m_dirc * 11;
	else
		m_knife_pos.x -= m_dirc * 15;

	m_knifeSpr.setPosition(m_knife_pos);
	m_knifeSpr_op.setPosition(m_knife_pos);
}

void Knife::draw(sf::RenderWindow& window, float clock_sample) 
{
	if (m_dirc == 2)//right
		window.draw(m_knifeSpr);
	else//left
		window.draw(m_knifeSpr_op);
}


void Knife::setknife()
{
	m_knifeSpr.setTexture(*Singleton::show().get_pic(1));
	m_knifeSpr.setScale(0.6,0.6);
	m_knifeSpr.setPosition(m_knife_pos);
	m_knifeSpr_op.setTexture(*Singleton::show().get_pic(25));
	m_knifeSpr_op.setScale(sf::Vector2f(0.6,0.6));
	m_knifeSpr_op.setPosition(m_knife_pos);
}

void Knife::set_y_position(float y)
{
}

sf::Sprite Knife::get_sprite()
{
	if (m_dirc == 2)//right
		return(m_knifeSpr);
	else//left
		return(m_knifeSpr_op);
}

void Knife::set_pos(Player& p)
{
	sf::Vector2f pos = p.getPosition();
	m_knife_pos.x = pos.x * SHAPE;
	m_knife_pos.y = pos.y * SHAPE;
	m_knife_pos.x += (TO_CENTER + 0.3);
	m_knife_pos.y += TO_CENTER / 3;
}
