#pragma once
#include "Monster.h"
#include <ostream>


class Snake : public Monster  
{

public:

	//----Constructor for Snake object------
	Snake(sf::Vector2i location, char icon);

	void draw(sf::RenderWindow& window, float clock_sample)override; // draw func
	void update_time_counter(float add)  ; // func to update time counter
	void set_direction(); // sets Birds direction
	void move(float x, float y, float dirc) override {}; // empty definition used for polymorphism
	void movement(float x, float y, float dirc) override; // empty definition used for polymorphism
	void set_y_position(float y) override {}; // empty definition used for polymorphism
	void setLocation(float newState) { m_location.x *= newState; };
	void set_location(sf::Vector2f location); // sets Bird location
	void fix_position(); // fixes Bird position
	void setScale() ;
	void setTimes()  { m_times += 1; };
	directions_t get_direction() const; // gets directions from enam
	const sf::Vector2f get_location() const; // gets location vertex
	const sf::Sprite get_sprite() const { return m_pic; }; // gets Bird picture
	const int getTimes() const { return m_times; }; // snake lives

private:

	float m_x;
	float m_time_counter; // lives counter
	int m_times; // lives member
	float m_scale = 0.7;
};
