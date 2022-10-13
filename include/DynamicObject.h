#pragma once

#include "Object.h"


enum directions_t
{
	down_t,	left_t, right_t, up_t, stand_t
};

class DynamicObject : public Object
{

public:

	//----Constructor for DynamicObject------
	DynamicObject();
	virtual void move(float x, float y, float dirc) = 0;
	virtual void set_y_position(float y) = 0;
	~DynamicObject() = default;


protected:

	float m_speed;
	float from_x;
	float from_y;
	int change_pic;
	directions_t m_direction;

};