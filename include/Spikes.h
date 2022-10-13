#pragma once
#include "StaticObject.h"

class Spikes : public StaticObject
{

public:

	//----Constructor for Spikes object------
	Spikes(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~Spikes() = default;

private:

};

