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
	void set_direction();
	void move(float x, float y, float dirc) override {}; // empty
	void movement(float x, float y, float dirc) override; // empty
	void set_y_position(float y) override {}; // empty
	void setLocation(float newState) { m_location.x *= newState; };
	void set_location(sf::Vector2f location);
	void fix_position() ;
	void setScale() ;
	void setTimes()  { m_times += 1; };
	directions_t get_direction() const;
	const sf::Vector2f get_location() const;
	const sf::Sprite get_sprite() const { return m_pic; };
	const int getTimes() const { return m_times; };

private:

	float m_x;
	float m_time_counter;
	int m_times;
	float m_scale = 0.7;
};
