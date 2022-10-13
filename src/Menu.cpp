#pragma once

#include "Menu.h"

Menu::Menu() : m_width(LEVELWIDTH), m_height(LEVELHEIGHT), m_choice(4), help_mode(false)
{
	m_font.loadFromFile("font.ttf");

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		m_menu[i].setOutlineThickness(10);
		m_menu[i].setFont(m_font);
		if (i == 0)
		{
			m_menu[i].setColor(sf::Color::Cyan);
			m_menu[i].setString("JILL OF THE\n    JUNGLE");
			m_menu[i].setPosition(sf::Vector2f((m_width / 4.7), m_height / 15));
			m_menu[i].setCharacterSize(140);
		}
		if (i != 0)
			m_menu[i].setCharacterSize(100);
		if (i == 1)
		{
			m_menu[i].setColor(sf::Color::Red);
			m_menu[i].setString("Play");
			m_menu[i].setPosition(sf::Vector2f((m_width / 2.3), m_height / (MAX_NUMBER_OF_ITEMS) * 3.1));
		}
		if (i == 2)
		{
			m_menu[i].setColor(sf::Color::White);
			m_menu[i].setString("Controls");
			m_menu[i].setPosition(sf::Vector2f(m_width / 2.7, m_height / (MAX_NUMBER_OF_ITEMS) * 3.8));
		}
		if (i == 3)
		{
			m_menu[i].setColor(sf::Color::White);
			m_menu[i].setString("Help");
			m_menu[i].setPosition(sf::Vector2f(m_width / 2.3, m_height / (MAX_NUMBER_OF_ITEMS) * 4.5));
		}
		if (i == 4)
		{
			m_menu[i].setColor(sf::Color::White);
			m_menu[i].setString("Exit");
			m_menu[i].setPosition(sf::Vector2f(m_width / 2.3, m_height / (MAX_NUMBER_OF_ITEMS) * 5.3));
		}
		if (i == 5)
		{
			m_menu[i].setColor(sf::Color::White);
			m_menu[i].setString("Jill");
			m_menu[i].setPosition(1060, 750);
		}
		if (i == 6)
		{
			m_menu[i].setColor(sf::Color::Red);
			m_menu[i].setString("Bill");
			m_menu[i].setPosition(280, 750);
		}
	}

	m_selectedItemIndex = 1;

	
	m_menuBack[1].setSize(sf::Vector2f(m_width, m_height));
	m_menuBack[1].setTexture(Singleton::show().get_pic(2)); // player choose menu
	m_menuBack[1].setPosition(0, 0);

	m_player_pic.setTexture(*Singleton::show().get_pic(6));
	m_player_pic.setPosition(0, 0);

	m_controls_pic.setTexture(*Singleton::show().get_pic(7));
	m_controls_pic.setPosition(0, 0);

	m_help_pic.setTexture(*Singleton::show().get_pic(8));
	m_help_pic.setPosition(0, 0);
}


void Menu::run() 
{
	Singleton::show().get_sound(1).play();
	bool chooseMode = false;
	Controller newGame;	//creating EditorManager member 

	sf::Event event;
	sf::RenderWindow menu_window(sf::VideoMode(m_width, m_height), "JILL OF THE JUNGLE", sf::Style::Default);
	draw(menu_window);
	menu_window.display();
	help_mode = false;
	while (menu_window.isOpen())
	{
		while (menu_window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				help_mode = false;
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				MoveUp();
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				MoveDown();
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				if (m_selectedItemIndex == 1)
				{
					menu_window.close();
				}
				if (m_selectedItemIndex == 2)
				{
					help_mode = true;
					menu_window.clear();
					menu_window.draw(m_controls_pic);
					menu_window.display();
					break;
				}
				if (m_selectedItemIndex == 3)
				{
					help_mode = true;
					menu_window.clear();
					menu_window.draw(m_help_pic);
					menu_window.display();
					break;
				}
				if (m_selectedItemIndex == 4)
					exit(EXIT_SUCCESS);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				menu_window.close();
				return;
			}
			if (!help_mode)
			{
				draw(menu_window);
				menu_window.display();
			}
		}
	}

	sf::RenderWindow choose_window(sf::VideoMode(m_width, m_height), "JILL OF THE JUNGLE", sf::Style::Default);
	choose_window.clear();
	choose_window.draw(m_player_pic);
	choose_window.draw(m_menu[5]);
	choose_window.draw(m_menu[6]);
	choose_window.display();

	while (choose_window.isOpen())
	{
		while (choose_window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				MoveRight();
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				MoveLeft();
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				if (m_selectedItemIndex == 1)
				{
					choose_window.close();
				}
				if (m_selectedItemIndex == 2)
					exit(EXIT_SUCCESS);
			}
			choose_window.draw(m_player_pic);
			choose_window.draw(m_menu[5]);
			choose_window.draw(m_menu[6]);
			choose_window.display();
		}
	}
	Singleton::show().get_sound(1).stop();
	newGame.run(m_width, m_height, m_choice);	//start Editor
}


void Menu::draw(sf::RenderWindow& window)
{
	window.draw(m_menuBack[1]);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS - 2; i++)
	{
		window.draw(m_menu[i]);
	}
}
void Menu::MoveUp() 
{
	if (m_selectedItemIndex - 1 >= 1)
	{
		m_menu[m_selectedItemIndex].setColor(sf::Color::White);
		m_selectedItemIndex--;
		m_menu[m_selectedItemIndex].setColor(sf::Color::Red);
	}
}
void Menu::MoveDown()
{
	if (m_selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS - 2)
	{
		m_menu[m_selectedItemIndex].setColor(sf::Color::White);
		m_selectedItemIndex++;
		m_menu[m_selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveLeft() 
{
	m_menu[5].setColor(sf::Color::White);
	m_choice = 4;
	m_menu[6].setColor(sf::Color::Red);
}

void Menu::MoveRight() 
{
	m_menu[6].setColor(sf::Color::White);
	m_choice = 3;
	m_menu[5].setColor(sf::Color::Red);
}

void Menu::setMusic() 
{
	if (!menuMusic.openFromFile("MenuMusic.ogg")) //move to singleton
		std::cout << "ERROR" << std::endl;

	menuMusic.setLoop(true);
	menuMusic.setVolume(2);
	menuMusic.play();
}

Menu::~Menu()
{

}