#pragma once

#include "Gate.h"

class GemGate : public Gate
{

public:

	//----Constructor for GemGate object------
	GemGate(sf::Vector2i location, char icon) ;
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~GemGate() = default;
};