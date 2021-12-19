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
	void move(float x, float y, float dirc)override; // knife movement function
	void draw(sf::RenderWindow& window, float clock_sample)override; // draws knives 
	void setknife() ; // sets knives
	void set_pos(Player& p); // sets knife position
	void set_dirc(float dirc) { m_dirc = dirc; }; // sets knives direction
	void set_y_position(float y)override; // sets knives y position
	void set_distance() { m_distance--; }; // sets knives distance
	const int get_distance() const { return m_distance; }; // gets knives distance
	void setLocation(float newState) {}; // sets knives location
	sf::Sprite get_sprite()override; // gets knives pictures
	~Knife() = default;

private:

	sf::Sprite m_knifeSpr; // kmife picture
	sf::Sprite m_knifeSpr_op; // knife opisite picture
	int m_distance = 40; // distance of knife until it disapears
};