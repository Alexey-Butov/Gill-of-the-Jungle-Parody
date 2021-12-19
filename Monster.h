#pragma once
#include "DynamicObject.h"

class Monster : public DynamicObject
{

public:

	//----Constructors for monster base-----
	Monster();
	~Monster();
	void move(float x, float y, float dirc) override {}; // move monster 
	void set_y_position(float y) override {} ; // monster y position
	sf::Sprite get_sprite() override { return m_pic; }; // monster picture

	virtual void movement(float x, float y, float dirc) = 0; // monster movement

private:

};
