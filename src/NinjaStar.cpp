#pragma once

#include "NinjaStar.h"

NinjaStar::NinjaStar(Player& p):m_pic_frame(0)
{
	set_pos(p);
	setNinjaStar();
}

void NinjaStar::move(float x, float y, float dirc) 
{
	if (m_dirc == 2)
		m_knife_pos.x += m_dirc * 11;
	else
		m_knife_pos.x -= m_dirc * 11;

	m_NinjaStarSprite.setPosition(m_knife_pos);
}

void NinjaStar::draw(sf::RenderWindow& window, float clock_sample) 
{
	m_pic_frame = (m_pic_frame + SHAPE) % (5 * SHAPE);
	m_NinjaStarSprite.setTextureRect(sf::IntRect(m_pic_frame, 0, SHAPE, SHAPE));

	window.draw(m_NinjaStarSprite);
}


void NinjaStar::setNinjaStar() 
{
	m_NinjaStarSprite.setTexture(*Singleton::show().get_pic(21));
	m_knife_pos.y -= 0.5;
	m_NinjaStarSprite.setPosition(m_knife_pos);
	m_NinjaStarSprite.scale(0.3,0.3);
}

void NinjaStar::set_y_position(float y) 
{
}

sf::Sprite NinjaStar::get_sprite() 
{
	return(m_NinjaStarSprite);
}

void NinjaStar::set_pos(Player& p) 
{
	sf::Vector2f pos = p.getPosition();
	m_knife_pos.x = pos.x * SHAPE;
	m_knife_pos.y = pos.y * SHAPE;
	m_knife_pos.x += TO_CENTER;
	m_knife_pos.y += (TO_CENTER +0.3) ;
}
