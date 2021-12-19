#pragma once
#include "StaticObject.h"

class Vine : public StaticObject
{

public:

	//----Constructor for Vine object------
	Vine(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample); // draws the object on board
	void changPic()override {}; // changes the picture for animation
	sf::Sprite get_sprite()override { return m_pic; }; // gets picture
	void setLocation(float newState) {}; // sets objects location
	~Vine() = default;

private:

};

