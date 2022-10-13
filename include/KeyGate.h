#pragma once

#include "Gate.h"

class KeyGate : public Gate
{

public:

	//----Constructor for KeyGate object------
	KeyGate(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample) ;
	void changPic()override;
	sf::Sprite get_sprite()override { return m_pic; };
	void setLocation(float newState) {};
	~KeyGate() = default;

private:

	sf::Sprite m_openDoor;
	bool m_open;
};

