#pragma once
#include <Controller.h>
#include <Wall.h>
#include <Apple.h>
#include <Diamond.h>
#include <Floor.h>
#include <GemGate.h>
#include <KeyGate.h>
#include <Spikes.h>
#include <Item.h>
#include <Key.h>
#include <Vine.h>
#include "Board.h"
#include "Collision.h"
#include "SpecialWall.h"
#include "Frog.h"
#include "Alligator.h"
#include "PresentLife.h"
#include "PresentScore.h"
#include "PresentTime.h"
#include "PresentShield.h"



// build the level by the level number.
Board::Board(int level): colided(false), knifeColided(false), m_diamonds(ZERO), m_fallSpeed(ZERO)
{
	m_level = level;
	ifstream file; //to read from file.
	char num = (char)(m_level)+'0';
	string end = ".txt";
	string file_name = "";
	file_name += num;
	file_name += end;
	file.open(file_name); //the name of the file.
	copy_to_file_vector(file); //copy to the file vector.
	make_m_board(); //do assign to the m_board.
	define_m_board(m_file_vector); //copy to the static vector.
}


//draw the static objects on the board.
void Board::draw(sf::RenderWindow& win, float clock_sample)
{
	for (int y = ZERO; y < m_length; y++)
	{
		for (int x = ZERO; x < m_width; x++)
		{
			if (m_board[y][x])//if not null
				if(typeid(m_board[y][x]) != typeid(Player))
					m_board[y][x]->draw(win, clock_sample);
		}
	}
}

void Board::moveMonsters(sf::Vector2f playerLoc, float clock_sample) const
{
	for (int i = ZERO; i < m_monster.size(); i++)
		m_monster[i]->movement(playerLoc.x, clock_sample, playerLoc.y);
}

void Board::drawMonsters(sf::RenderWindow& win, float clock_sample) const
{
	for (int i = ZERO; i < m_monster.size(); i++)
			m_monster[i]->draw(win, clock_sample);
}

//return the width
const int Board::get_width() const
{
	return m_width;
}


//return the lenth
const int Board::get_length() const
{
	return m_length;
}


//return the lenth
const int Board::get_levelTime() const
{
	return m_levelTime;
}

//return the lenth
const int Board::get_keys() const
{
	return m_keys;
}

//return the lenth
const int Board::get_diamonds() const
{
	return m_diamonds;
}


// copy the level string from file to the string vector.
void Board::copy_to_file_vector(ifstream& file) 
{

	string line;

	file >> m_length >> m_width >> m_levelTime >> m_keys >> m_diamonds; //read width, length, levelTime, keys, diamonds

	getline(file, line); //eat enter;

	for (int index = ZERO; index < m_length; index++) // build the map
	{
		getline(file, line);
		m_file_vector.emplace_back(line); // reads the file into vector line by line
	}
}


// translate the static & dynamic objects from location and icon (from the file vector) to 
//static objects . and keep ditails about player and the monsters.
void Board::define_m_board(vector<string>m_file_vector) 
{
	char icon;
	sf::Vector2i location;

	for (int y = ZERO; y < m_length; y++)
	{
		for (int x = ZERO; x < m_width; x++)
		{
			location.x = x;
			location.y = y;

			icon = m_file_vector[y][x];
			
			switch (icon) 
			{
				case '#':m_board[y][x] = make_unique <Floor>(location, '#'); //floor
					break;
				case 'A':m_board[y][x] = make_unique <Apple>(location, 'A'); //Apple
					break;
				case 'W':m_board[y][x] = make_unique <Wall>(location, 'W'); //Wall
					break;
				case 'G':m_board[y][x] = make_unique <KeyGate>(location, 'G'); //KeyGate
					m_KeyGate.x = x;
					m_KeyGate.y = y;
					break;
				case 'K':m_board[y][x] = make_unique <Key>(location, 'K'); //Key
					break;
				case 'S':m_board[y][x] = make_unique <Spikes>(location, 'S'); //Spikes
					break;
				case 'V':m_board[y][x] = make_unique <Vine>(location, 'V'); //Vine
					break;
				case 'D':m_board[y][x] = make_unique <Diamond>(location, 'D');//Diamond
					break;
				case 'J':m_board[y][x] = make_unique <GemGate>(location, 'J'); //gemgate
					break;
				case '@':m_board[y][x] = make_unique <SpecialWall>(location, '@'); //SpecialWall
					break;
				case 'P':
					playerLoc = location;
					break;
				case '!':
					m_monster.emplace_back(make_unique <Alligator>(location, '!')); //Alligator
					break;
				case 'T':
					m_monster.emplace_back(make_unique <Ant>(location, 'T')); //Ant
					break;
				case 'Y':
					m_monster.emplace_back(make_unique <Bee>(location, 'Y')); //Bee
					break;
				case 'B':
					m_monster.emplace_back(make_unique <Bird>(location, 'B')); //Bird
					break;
				case 'U':
					m_monster.emplace_back(make_unique <Snake>(location, 'U')); //Snake
					break;
				case 'F':
					m_monster.emplace_back( make_unique <Frog>(location, 'F')); //Frog
					break;
			}
		}
	}
}


// build the m_board vector and define him to be nullptr in every cell.
void Board::make_m_board() 
{
	m_board.resize(m_length);

	for (auto& m : m_board)
		m.resize(m_width);

	for (int i = ZERO; i < m_length; i++)
	{
		for (int j = ZERO; j < m_width; j++)
			m_board[i][j] = nullptr; 
	}
}


const sf::Vector2i Board::get_player() const
{
	return playerLoc;
}


// will release a unique ptr of an object on board.
void Board::set_object_null(sf::Vector2f place)
{
	sf::Vector2i object;
	object.x = place.x;
	object.y = place.y;

	m_board[object.y][object.x] = nullptr;
}


void Board::openKeyGate() const
{
	m_board[m_KeyGate.y][m_KeyGate.x]->changPic();
}

void Board::CheckForCollision(Player& p) 
{
	for (int i = ZERO; i < m_length; i++)
	{
		for (int j = ZERO; j < m_width; j++)
		{
			if (m_board[i][j] != nullptr)
			{
				if (ObjectsCollided(p, *m_board[i][j]))
				{
					 Collision::instance().processCollision(p, *m_board[i][j]);
					 if (typeid(*m_board[i][j]) == typeid(Apple) || typeid(*m_board[i][j]) == typeid(Key) ||
						 typeid(*m_board[i][j]) == typeid(Diamond) || (typeid(*m_board[i][j]) == typeid(GemGate) && p.getGemGatePassStatus()) || 
						 typeid(*m_board[i][j]) == typeid(PresentLife) || typeid(*m_board[i][j]) == typeid(PresentScore) ||
						 typeid(*m_board[i][j]) == typeid(PresentTime) || typeid(*m_board[i][j]) == typeid(PresentShield))
						 m_board[i][j] = nullptr;            //p.GemGate... -> if enough diamonds eaten open gate
				}
				
			}
		}
	}
	if (!colided && p.getShieldStatus() == false)
	{
		for (int z = 0; z < m_monster.size(); z++)
		{
			if (ObjectsCollided(p, *m_monster[z]))
			{
				Collision::instance().processCollision(p, *m_monster[z]);
			}
		}
	}
	else
		colided = false;
}

void Board::CheckForMonsCollision(Player& p, vector<Knife>& m_knifes, vector<NinjaStar>& m_Nstars) 
{
	for (int i = 0; i < m_length; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			for (int z = 0; z < m_monster.size(); z++)
			{
				if (m_board[i][j] != nullptr)
				{
					if (ObjectsCollided(*m_monster[z], *m_board[i][j]))
					{
						Collision::instance().processCollision(*m_monster[z], *m_board[i][j]);
					}
				}
			}
		}
	}
	if(p.getShieldStatus() == false)
	{
		for (int z = 0; z < m_monster.size(); z++)
		{
			if (ObjectsCollided(*m_monster[z], p))
			{
				colided = true;
				Collision::instance().processCollision(*m_monster[z], p);
			}
		}
	}

	for(int i = ZERO; i < m_knifes.size(); i++)
	{
		for(int z = ZERO; z < m_monster.size(); z++)
		{
			if (ObjectsCollided(m_knifes[i], *m_monster[z]))
			{
				if(typeid(*m_monster[z]) == typeid(Snake))
				{
					Snake& s = static_cast<Snake&>(*m_monster[z]);
					Collision::instance().processCollision(*m_monster[z] ,m_knifes[i]);
					if(s.getTimes() == THREE)
						m_monster.erase(m_monster.begin() + z);
				}
				else
					m_monster.erase(m_monster.begin() + z);

				m_knifes.erase(m_knifes.begin() + i);
				break;
			}
		}
		if(m_knifes.empty() || m_monster.empty())
			break;
	}
	for(int i = ZERO; i < m_Nstars.size(); i++)
	{
		for(int z = ZERO; z < m_monster.size(); z++)
		{
			if (ObjectsCollided(m_Nstars[i], *m_monster[z]))
			{				
				if(typeid(*m_monster[z]) == typeid(Snake))
				{
					Snake& s = static_cast<Snake&>(*m_monster[z]);
					Collision::instance().processCollision(*m_monster[z] , m_Nstars[i]);
					if (s.getTimes() == THREE)
					{
						m_monster.erase(m_monster.begin() + z); //ITERATOR
					}					
				}
				else
				{
					m_monster.erase(m_monster.begin() + z);
				}	
		    	m_Nstars.erase(m_Nstars.begin() + i);
				break;
			}
		}
		if(m_Nstars.empty() || m_monster.empty())
			break;
	}
}
void Board::checkWeaponColission(vector<Knife>& m_knifes, vector<NinjaStar>& m_Nstars) 
{//---------------------------------------------weapons -> monsters-------------------------------
	for(int i = ZERO; i < m_knifes.size(); i++)
	{
		for(int z = ZERO; z < m_monster.size(); z++)
		{
			if (ObjectsCollided(m_knifes[i], *m_monster[z]))
			{
				if(typeid(*m_monster[z]) == typeid(Snake))
				{
					Snake& s = static_cast<Snake&>(*m_monster[z]);
					Collision::instance().processCollision(m_knifes[i], *m_monster[z]);
					if(s.getTimes() == THREE)
						m_monster.erase(m_monster.begin() + z); //ITERATOR
				}
				else
				{
					m_monster.erase(m_monster.begin() + z);
				}	
				m_knifes.erase(m_knifes.begin() + i);
				break;
			}
		}
		if(m_knifes.empty() || m_monster.empty())
			break;
	}

	for(int i = ZERO; i < m_Nstars.size(); i++)
	{
		for(int z = ZERO; z < m_monster.size(); z++)
		{
			if (ObjectsCollided(m_Nstars[i], *m_monster[z]))
			{
				if(typeid(*m_monster[z]) == typeid(Snake))
				{
					Snake& s = static_cast<Snake&>(*m_monster[z]);
					Collision::instance().processCollision(m_Nstars[i], *m_monster[z]);
					if(s.getTimes() == THREE)
						m_monster.erase(m_monster.begin() + z);
					m_Nstars.erase(m_Nstars.begin() + i);
					break;
				}
				else
				{
					m_monster.erase(m_monster.begin() + z);
					m_Nstars.erase(m_Nstars.begin() + i);
					break;
				}
			}
		}
		if(m_Nstars.empty() || m_monster.empty())
			break;
	}
//---------------------------------------------weapons -> monsters-------------------------------
//---------------------------------------------weapons -> walls-------------------------------
	for(int x = ZERO; x < m_knifes.size(); x++)
	{
		knifeColided = false;
		for (int i = ZERO; i < m_length; i++)
		{
			for (int j = ZERO; j < m_width; j++)
			{
				if (m_board[i][j] != nullptr)
				{
					if (ObjectsCollided(m_knifes[x], *m_board[i][j]))
					{
						 if (typeid(*m_board[i][j]) == typeid(Wall) || typeid(*m_board[i][j]) == typeid(GemGate) || 
							 typeid(*m_board[i][j]) == typeid(SpecialWall)) 
							 {
								m_knifes.erase(m_knifes.begin() + x);
								knifeColided = true;
								break;
							 }	
					}
				}
			}
			if(m_knifes.empty() || knifeColided)
				break;	
		}
		if(m_knifes.empty())
			break;
	}
	for(int x = ZERO; x < m_Nstars.size(); x++)
	{
		knifeColided = false;
		for (int i = ZERO; i < m_length; i++)
		{
			for (int j = ZERO; j < m_width; j++)
			{
				if (m_board[i][j] != nullptr)
				{
					if (ObjectsCollided(m_Nstars[x], *m_board[i][j]))
					{
						 if (typeid(*m_board[i][j]) == typeid(Wall) || typeid(*m_board[i][j]) == typeid(GemGate) || 
							 typeid(*m_board[i][j]) == typeid(SpecialWall)) 
							 {
								m_Nstars.erase(m_Nstars.begin() + x);
								knifeColided = true;
								break;
							 }	
					}
				}
			}
			if(m_Nstars.empty() || knifeColided)
				break;	
		}
		if(m_Nstars.empty())
			break;
	}
//---------------------------------------------------------------------------------------------
}
bool Board::ObjectsCollided(Object& obj1, Object& obj2) const
{
	return obj1.get_sprite().getGlobalBounds().intersects(obj2.get_sprite().getGlobalBounds());
}

bool Board::isFloating(Player& p) const
{
	sf::Vector2f pos = p.getPosition();
	pos.x = (pos.x * SHAPE + TO_CENTER) / SHAPE;
	pos.y = (pos.y * SHAPE + TO_CENTER) / SHAPE;


	if (m_board[(int)(pos.y) + ONE][(int)pos.x] == nullptr)
		return false;
	if (typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(Floor) ||
		typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(Wall)  ||
		typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(Vine)  ||
		typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(SpecialWall))
		return true;
}

bool Board::isOnFloor(Player& p) const
{
	sf::Vector2f pos = p.getPosition();
	pos.x = (pos.x * SHAPE + TO_CENTER) / SHAPE;
	pos.y = (pos.y * SHAPE + TO_CENTER) / SHAPE;

	if (m_board[(int)(pos.y) + ONE][(int)pos.x] == nullptr)
		return false;
	if (typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(Floor))
		return true;
	else
		return false;
}

bool Board::isOnGround(Player& p) const
{
	sf::Vector2f pos = p.getPosition();
	pos.x = (pos.x * SHAPE + TO_CENTER) / SHAPE;
	pos.y = (pos.y * SHAPE + TO_CENTER) / SHAPE;

	if (m_board[(int)(pos.y) + ONE][(int)pos.x] == nullptr)
		return false;
	if (typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(Floor) || 
		typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(Wall))
		return true;
	else
		return false;
}

bool Board::isAboveLadder(Player& p) const
{
	sf::Vector2f pos = p.getPosition();
	pos.x = (pos.x * SHAPE ) / SHAPE;
	pos.y = (pos.y * SHAPE + SHAPE) / SHAPE;

	if (m_board[(int)(pos.y) + ONE][(int)pos.x] == nullptr)
		return false;
	if (typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(SpecialWall))
		return true;
	else
		return false;
}


const StaticObject* Board::get_object(sf::Vector2f place) const
{
	sf::Vector2i object;
	object.x = (int)place.x ;
	object.y = (int)place.y ;
	if (object.y >= m_length || object.x >= m_width)
		return nullptr;

	return m_board[object.y][object.x].get();
}

bool Board::isClimbing(Player& p) const
{
	sf::Vector2f pos = p.getPosition();

	pos.y = (pos.y * SHAPE + SHAPE) / SHAPE;

	if (m_board[(int)(pos.y) + ONE][(int)pos.x] == nullptr)
		return false;
	if (typeid(*m_board[(int)(pos.y) + ONE][(int)pos.x]) == typeid(SpecialWall))
		return true;
	else
		return false;
}

void Board::handleFloating(Player& p) 
{	
	m_fallSpeed++;
	if(m_fallSpeed == TWO)
	{
		CheckForCollision(p);
		sf::Vector2f pos = p.getPosition();
		float x = p.get_direction();
		if (pos.y > EIGHT)
			p.set_y_position(NINE);
		else
		{
			pos.y += ONE;
			if (x == ONE)
				pos.x -= POINTFIVE;
			else
				pos.x += POINTFIVE;
			p.set_location(pos);
		}
		m_fallSpeed = ZERO;
	}
}	


const int Board::get_time() const
{
	return m_time;
}

void Board::set_time(int elapsed) 
{
	m_time = elapsed;
}

//will set the gift on the static board by location and icon.
void Board::set_gift(int x, int y, char icon)
{
	sf::Vector2i location;
	location.x = x;
	location.y = y;

	switch (icon)
	{
	case '1': m_board[y][x] = make_unique <PresentLife>(location, '1');
		break;
	case '2': m_board[y][x] = make_unique <PresentScore>(location, '2');
		break;
	case '3': m_board[y][x] = make_unique <PresentTime>(location, '3');
		break;
	case '4': m_board[y][x] = make_unique <PresentShield>(location, '4');
		break;
	}
}