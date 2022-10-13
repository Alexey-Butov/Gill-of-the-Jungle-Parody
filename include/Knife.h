#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> 
#include <stdlib.h>
#include <string>
#include <vector>
#include "Player.h"
#include "Weapon.h"
#include "Singleton.h"

class Knife : public Weapon
{
public:

	//----Constructor for knife object------
	Knife(Player& p);
	void move(float x, float y, float dirc)override;
	void draw(sf::RenderWindow& window, float clock_sample)override;
	void setknife() ;
	void set_pos(Player& p);
	void set_dirc(float dirc) { m_dirc = dirc; };
	void set_y_position(float y)override;
	void set_distance() { m_distance--; };
	const int get_distance() const { return m_distance; };
	void setLocation(float newState) {};
	sf::Sprite get_sprite()override;
	~Knife() = default;

private:

	sf::Sprite m_knifeSpr;
	sf::Sprite m_knifeSpr_op;
	int m_distance = 40;
};