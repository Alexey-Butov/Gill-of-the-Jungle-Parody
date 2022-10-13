#pragma once

#include "StatusBar.h"
#include <iostream>

StatusBar::StatusBar(int l, int s, int k, int d)
	: m_lives(l), m_score(s), m_keys(k), m_diamond(d), m_time_bonus(0), m_keysGoal(0), m_minutes(0)
{
	m_font.loadFromFile("font_statusBar.ttf");
	lives.setCharacterSize(60);
	score.setCharacterSize(60);
	keys.setCharacterSize(60);
	diamond.setCharacterSize(55);
	lives.setScale(0.2, 10.5);
	score.setScale(0.2, 10.5);
	keys.setScale(0.2, 10.5);
	diamond.setScale(0.2, 10.5);
	lives.setPosition(40, 40);
	score.setPosition(125, 25);
	keys.setPosition(213, 30);
	diamond.setPosition(303, 70);
	lives.setFillColor(sf::Color::White);
	score.setFillColor(sf::Color::White);
	keys.setFillColor(sf::Color::White);
	diamond.setFillColor(sf::Color::White);
	lives.setFont(m_font);
	score.setFont(m_font);
	keys.setFont(m_font);
	diamond.setFont(m_font);
}

void StatusBar::set_goals(int &keys, int &diamonds)
{
	m_keysGoal = keys;
	m_diamondsGoal = diamonds;
}
const int StatusBar::get_lives()  const
{
	return m_lives;
}

const int StatusBar::get_score() const
{
	return m_score;
}

const int StatusBar::get_keys() const
{
	return m_keys;
}

int StatusBar::get_diamond()  
{
	return m_diamond;
}

const int StatusBar::get_key_goal() const
{
	return m_keysGoal;
}

const int StatusBar::get_diamond_goal() const
{
	return m_diamondsGoal;
}
void StatusBar::set_lives(int lives)
{
	m_lives += lives;
}

void StatusBar::set_score(int score) 
{
	m_score += score;
}

void StatusBar::set_keys(int keys) 
{
	m_keys += keys;
}

void StatusBar::set_diamond(int diamond) 
{
	m_diamond += diamond;
}

void StatusBar::draw(sf::RenderWindow& window) 
{
	s_lives.str("");
	s_score.str("");
	s_keys.str("");
	s_diamond.str("");
	s_lives << "Lives: " << get_lives();
	lives.setString(s_lives.str());
	s_score << "Score: " << get_score();
	score.setString(s_score.str());
	s_keys << "  keys: " << get_keys() <<"/"<< m_keysGoal;
	keys.setString(s_keys.str());
	s_diamond << "Diamonds: " << get_diamond() <<"/"<< m_diamondsGoal;
	diamond.setString(s_diamond.str());
	window.draw(lives);
	window.draw(score);
	window.draw(keys);
	window.draw(diamond);
}


//set game clock
void StatusBar::setGameClock(int elapsedTime, sf::RenderWindow& window)
{
	m_minutes = (elapsedTime / 60) + m_time_bonus;

	if ((elapsedTime % 60) < 10 && (m_minutes) < 10)
		m_clockNum.setString("0" + std::to_string(m_minutes) + ":0" + std::to_string(elapsedTime % 60));
	else if ((elapsedTime % 60) >= 10 && (m_minutes) >= 10)
		m_clockNum.setString(std::to_string(m_minutes) + ":" + std::to_string(elapsedTime % 60));
	if ((elapsedTime % 60) >= 10 && (m_minutes) < 10)
		m_clockNum.setString("0" + std::to_string(m_minutes) + ":" + std::to_string(elapsedTime % 60));
	else
		m_clockNum.setString("0" + std::to_string(m_minutes) + ":0" + std::to_string(elapsedTime % 60));

	m_clockNum.setFont(m_font);
	m_clockNum.setStyle(sf::Text::Regular);
	m_clockNum.setCharacterSize(60);
	m_clockNum.setScale(0.2, 10.5);
	m_clockNum.setPosition(400, 30);
	
	if (elapsedTime < 10)
	{
		if(elapsedTime % 2 == 0)
			m_clockNum.setFillColor(sf::Color::Red);
		else
			m_clockNum.setFillColor(sf::Color::White);
	}
	else
		m_clockNum.setFillColor(sf::Color::White);

	window.draw(m_clockNum);
}

void StatusBar::resetResources() 
{
	m_diamond = 0;
	m_keys = 0;
}

StatusBar::~StatusBar()
{
}
