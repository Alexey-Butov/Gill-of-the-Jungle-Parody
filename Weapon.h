#pragma once

#include "DynamicObject.h"


class Weapon : public DynamicObject
{
public:

	//----Constructor for weapon base------
	Weapon();
	~Weapon() = default;

protected:

	sf::Vector2f m_knife_pos; // knife position
	sf::Texture m_knifeTex; // knife texture
	float m_dirc; // weapon direction
};