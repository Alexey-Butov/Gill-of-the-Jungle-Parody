#pragma once

#include "Gate.h"

class KeyGate : public Gate
{

public:

	//----Constructor for KeyGate object------
	KeyGate(sf::Vector2i location, char icon);
	void draw(sf::RenderWindow& win, float clock_sample); // draws the object on board
	void changPic(); // changes the picture for animation
	sf::Sprite get_sprite()override { return m_pic; }; // gets picture
	void setLocation(float newState) {}; // sets objects location
	~KeyGate() = default;

private:

	sf::Sprite m_openDoor;
	bool m_open;
};

