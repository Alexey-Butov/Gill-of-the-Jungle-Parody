#pragma once
#include "Monster.h"
#include <ostream>


class Frog : public Monster
{

public:

	//----Constructor for Frog object------
	Frog(sf::Vector2i location, char icon);

	void draw(sf::RenderWindow& window, float clock_sample)override; //draw func

	void update_time_counter(float add) ; // func to update time counter

	void set_direction() ;

	directions_t get_direction() ;
	sf::Vector2f get_location() ;

	void move(float x, float y, float dirc) override {}; //empty

	void movement(float x, float y, float dirc) override; //empty
	void set_y_position(float y) override {}; //empty
	void setLocation(float newState)  { m_location.x *= newState; };
	sf::Sprite get_sprite() const { return m_pic; };

	void set_location(sf::Vector2f location) ;
	void fix_position() ;

private:

	float m_x;
	float m_time_counter;
};
