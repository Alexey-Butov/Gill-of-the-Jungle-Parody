#pragma once

#include "DynamicObject.h"


class Weapon : public DynamicObject
{
public:

	//----Constructor for weapon base------
	Weapon();
	~Weapon() = default;

protected:

	sf::Vector2f m_knife_pos;
	sf::Texture m_knifeTex;
	float m_dirc;
};