#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <ostream>
#include <sstream>

#include "singleton.h"

class StatusBar
{
public:

	//-------------Constructor for StatusBar--------------
	StatusBar(int lives, int score, int keys, int diamond);
	const int get_lives() const;
	const int get_score() const;
	const int get_keys() const;
	int get_diamond() ;
	const int get_key_goal() const;
	const int get_diamond_goal() const;
	void set_lives(int lives);
	void set_score(int score);	
	void set_keys(int keys);
	void set_time() {m_time_bonus += 1;};
	void set_diamond(int diamond);
	void set_goals(int &keys, int &diamonds);
	void resetResources() ;
	void draw(sf::RenderWindow& window) ;
	void setGameClock(int elapsedTime, sf::RenderWindow& window);
	~StatusBar();

private:

	int m_score, m_lives, m_keys, m_diamond, m_minutes, m_keysGoal, m_diamondsGoal, m_time_bonus;
	sf::Font m_font;
	std::ostringstream s_lives, s_score, s_keys,  s_diamond;
	sf::Text lives, score, keys, diamond, m_clockNum;
};

