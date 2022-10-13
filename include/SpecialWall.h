#pragma once
#include "StaticObject.h"

class SpecialWall : public StaticObject
{

public:

	//----Constructor for SpecialWall object------
	SpecialWall(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override {};
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~SpecialWall() = default;

private:

};
