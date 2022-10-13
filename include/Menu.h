#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <cstdlib> 
#include <iostream> 
#include <vector>
#include "Controller.h"
#include "singleton.h"

constexpr int MAX_NUMBER_OF_ITEMS = 7;


class Menu
{

public:

	//----Constructors for menu------
	Menu();
	~Menu();
	void run() ;
	void draw(sf::RenderWindow& window);
	void MoveUp() ;
	void MoveDown() ;
	void MoveLeft() ;
	void MoveRight() ;
	void setMusic() ;
	const int getPressedItem() const { return m_selectedItemIndex; }

private:

	bool help_mode;
	int m_choice;
	int m_selectedItemIndex;
	float m_width;
	float m_height;
	sf::Font m_font;
	sf::Text m_menu[MAX_NUMBER_OF_ITEMS];
	sf::RectangleShape m_menuBack[2];
	sf::Sprite m_back_pic;
	sf::Sprite m_player_pic;
	sf::Sprite m_help_pic;
	sf::Sprite m_controls_pic;
	sf::Music menuMusic;

};