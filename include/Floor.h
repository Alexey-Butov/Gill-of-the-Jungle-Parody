#pragma once

#include "StaticObject.h"

class Floor : public StaticObject
{

public:

	//----Constructor for Floor object------
	Floor(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~Floor() = default;

private:

};

