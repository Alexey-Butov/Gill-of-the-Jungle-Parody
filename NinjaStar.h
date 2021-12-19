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
	void move(float x, float y, float dirc)override; // knife movement function
	void draw(sf::RenderWindow& window, float clock_sample)override; // draws stars 
	void setNinjaStar() ; // sets stars
	void set_pos(Player& p) ; //sets stars position
	void set_dirc(float dirc) { m_dirc = dirc; }; // sets stars direction
	void set_y_position(float y)override; // sets stars y position
	void set_distance()  { m_distance--; } // sets stars distance
	const int get_distance() const { return m_distance; }; // gets stars distance
	sf::Sprite get_sprite()override; // gets stars pictures
	void setLocation(float newState){}; // sets stars location
	~NinjaStar() = default;

private:

	sf::Sprite m_NinjaStarSprite; // picture of a ninja star
	int m_distance = 40; // distance until the item dissapear
	int m_pic_frame;
};