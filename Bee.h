#pragma once
#include "Monster.h"
#include <ostream>


class Bee : public Monster
{

public:

	//----Constructor for Bee object------
	Bee();
	Bee(sf::Vector2i location, char icon) ;

	void draw(sf::RenderWindow& window, float clock_sample)override; // draw func

	void update_time_counter(float add) ; // func to update time counter

	void set_direction(); // sets Bees direction

	directions_t get_direction() const; // gets directions from enam
	const sf::Vector2f get_location() const; // gets location vertex

	void move(float x, float y, float dirc) override {}; // empty definition used for polymorphism

	void movement(float x, float y, float dirc) override; // empty definition used for polymorphism
	void set_y_position(float y) override { m_location.y = y; }; // empty definition used for polymorphism
	void setLocation(float newState)  { m_location.x *= newState; };
	const sf::Sprite get_sprite() const { return m_pic; }; // gets bees picture

	void set_location(sf::Vector2f location) ; // sets bees location
	void fix_position() ; // fixes bees position

private:

	float m_x;
	float m_y;
	float m_time_counter;
};
