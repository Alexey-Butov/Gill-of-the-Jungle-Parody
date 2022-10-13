#pragma once
#include "StaticObject.h"

class Vine : public StaticObject
{

public:

	//----Constructor for Vine object------
	Vine(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~Vine() = default;

private:

};

