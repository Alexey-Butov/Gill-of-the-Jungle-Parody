#pragma once

#include "Gate.h"

class GemGate : public Gate
{

public:

	//----Constructor for GemGate object------
	GemGate(sf::Vector2i location, char icon) ;
	void draw(sf::RenderWindow& win, float clock_sample); // draws the object on board
	void changPic()override {}; // changes the picture for animation
	sf::Sprite get_sprite()override { return m_pic; }; // gets picture
	void setLocation(float newState) {}; // sets objects location
	~GemGate() = default;
};