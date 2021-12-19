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
	void run() ; // runs the menu
	void draw(sf::RenderWindow& window); // draws menu
	void MoveUp() ; // move up on menu
	void MoveDown() ; // move down on menu
	void MoveLeft() ; // move left on menu
	void MoveRight() ; // move right on menu
	void setMusic() ; // sets menu music
	const int getPressedItem() const { return m_selectedItemIndex; };  // gets chosen item on menu

private:

	bool help_mode; // to enable help menu
	int m_choice; // menu choice
	int m_selectedItemIndex; // selected item on menu 
	float m_width; // window width
	float m_height; // window height
	sf::Font m_font; // menu font
	sf::Text m_menu[MAX_NUMBER_OF_ITEMS]; // menu options
	sf::RectangleShape m_menuBack[2];
	sf::Sprite m_back_pic; // menu background picture
	sf::Sprite m_player_pic; // player pictures for choosing
	sf::Sprite m_help_pic; // help menu picture
	sf::Sprite m_controls_pic; // controls menu picture
	sf::Music menuMusic; // menu music

};