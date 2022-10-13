#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> 
#include <stdlib.h>
#include <string>
#include <vector>
#include "Player.h"
#include "Weapon.h"
#include "singleton.h"

class NinjaStar : public Weapon
{

public:

	//----Constructor for NinjaStar object------
	NinjaStar(Player& p);
	void move(float x, float y, float dirc)override;
	void draw(sf::RenderWindow& window, float clock_sample)override;
	void setNinjaStar() ;
	void set_pos(Player& p) ;
	void set_dirc(float dirc) { m_dirc = dirc; };
	void set_y_position(float y)override;
	void set_distance()  { m_distance--; }
	const int get_distance() const { return m_distance; };
	sf::Sprite get_sprite()override;
	void setLocation(float newState){};
	~NinjaStar() = default;

private:

	sf::Sprite m_NinjaStarSprite;
	int m_distance = 40;
	int m_pic_frame;
};