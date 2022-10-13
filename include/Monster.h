#pragma once
#include "DynamicObject.h"

class Monster : public DynamicObject
{

public:

	//----Constructors for monster base-----
	Monster();
	~Monster();
	void move(float x, float y, float dirc) override {};
	void set_y_position(float y) override {} ;
	sf::Sprite get_sprite() override { return m_pic; };

	virtual void movement(float x, float y, float dirc) = 0;

private:

};
