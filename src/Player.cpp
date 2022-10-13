#pragma once

#include "Player.h"

Player::Player() : m_pic(0), m_status(3, 0, 0, 0), m_jump(false), m_climb(false), original_pos(0,0),m_shield(false)
{
	source.x = 0;
	source.y = 0;
}

void Player::setPlayer(sf::Vector2i pos, int x) 
{
	m_x = x;
	playerSpr.setTexture(*Singleton::show().get_pic(x));
	shield.setTexture(*Singleton::show().get_pic(37));
	shield.setOrigin(TO_CENTER / 2, TO_CENTER/2);
	shield.setScale(sf::Vector2f(2, 2));
	player_pos.x = (float)pos.x;
	player_pos.y = (float)pos.y;

	original_pos.x = player_pos.x;
	original_pos.y = player_pos.y;
	
    playerSpr.setPosition(player_pos.x* SHAPE, player_pos.y* SHAPE);
}


void Player::move(float x, float y, float dirc) 
{
	m_Xdistance = x;
	m_Ydistance = y / 60;

	if (player_pos.x < 0)
		player_pos.x = 1;

	if(dirc == 0)
		m_direction = down_t;
	else if(dirc == 1)
		m_direction = left_t;
	else if(dirc == 2)
		m_direction = right_t;
	else
		m_direction = up_t;
	if ((player_pos.x + x < 6000 - 100) && (player_pos.x  >= 0))
	{
		if ((m_direction == left_t || m_direction == right_t) && !m_jump)
			 y = 0;
		if(!(x < 0 && player_pos.x == 0))
		{
			source.y = dirc;
			if (y == 0)
			{
			    player_pos.x += x/2;
			    player_pos.y += y/50;
			}
			else if(m_jump)
			{
				player_pos.x += x/3;
				player_pos.y += y/60;
			}	
			else if (m_direction == up_t)
			{
				player_pos.y -= y / 8;
			}
			else if (m_direction == down_t)
			{
				source.y = up_t;
				player_pos.y += y / 15;
			}
			if (!m_jump)
			{
				m_pic = (m_pic + SHAPE) % (7 * SHAPE);
			}
		}
	}
}

void Player::set_y_position(float y) 
{
	player_pos.y = y;
}

void Player::setStatus(int &keys, int &diamonds) 
{
	m_status.set_goals(keys, diamonds);
}

void Player::draw(sf::RenderWindow& window, float gameClock) 
{	   
	sf::RectangleShape background(sf::Vector2f(451.0f, 1000.0f));
	background.setPosition(0, 0);
	background.setTexture(Singleton::show().get_pic(23));
	if(m_shield)
	{
		shieldTimer--;
		shield.setPosition(player_pos.x* SHAPE, player_pos.y* SHAPE);
		window.draw(shield);
		if(shieldTimer == 0)
		{
			shieldTimer = 70;
			m_shield = false;
		}
	}

	playerSpr.setTextureRect(sf::IntRect(m_pic, source.y * SHAPE, SHAPE, SHAPE));
	playerSpr.setPosition(player_pos.x* SHAPE, player_pos.y* SHAPE);
	window.draw(playerSpr);

	auto Temp = window.getView();

	viewStatus.reset(sf::FloatRect((float)0, (float)0, (float)window.getSize().x + 150, (float)window.getSize().y));
	viewStatus.setViewport(sf::FloatRect(0.0f, 0.f, 3.66f, 0.05f));
	window.setView(viewStatus);
	window.draw(background);

	m_status.setGameClock(gameClock, window);

	m_status.draw(window);	

	window.setView(Temp);
}

void Player::fix_position() 
{
	if (!m_jump)
		player_pos.x -= m_Xdistance;
	else
	{
		if (m_direction == left_t)
		{
			std::cout << "LEFT" << std::endl;
			player_pos.y -= m_Ydistance + 1;
			player_pos.x += (m_Xdistance + 1);
		}
		else if (m_direction == right_t)
		{
			std::cout << "RIGHT" << std::endl;
			player_pos.y -= m_Ydistance;
			player_pos.x -= (m_Xdistance + 0.5);
		}
		else
			player_pos.y -= m_Ydistance;
		
	}
}


// return the direction.
directions_t Player::get_direction() const
{
	return m_direction;
}


// update the location to new place.
void Player::set_location(sf::Vector2f newp) 
{
	player_pos = newp;
}

void Player::addKey()
{
	m_status.set_keys(1);
	if (getKeys() == getKeysGoal())
	{
		m_gotEnoughKeys = true;
	}
}

const sf::Vector2f Player::get_location() const
{
	return player_pos;
}

const int Player::getLives() const
{
	int lives = m_status.get_lives();
	return(lives);
}

const int Player::getKeys() const
{
	int keysNum = m_status.get_keys();
	return keysNum;
}
void Player::resetKeys() 
{
	m_status.resetResources();
}

void Player::decreaseLife() 
{ 
	Singleton::show().get_sound(5).play();
	m_status.set_lives(-1); 
}