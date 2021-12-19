#pragma once

#include <SFML\Graphics.hpp>
#include <Vector>
#include <string>
#include <fstream> 
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#include <memory>
#include "StaticObject.h"
#include "Player.h"
#include "SpecialWall.h"
#include "Monster.h"
#include "Knife.h"
#include "NinjaStar.h"

using std::vector;
using std::ifstream;
using std::string;
using std::make_unique;

constexpr double POINTFIVE = 0.5;

// The Board class represents all objects that are drawn on the screen
class Board
{

public:

	//----Constructor for Board------
	Board() = default;
	Board(int level);
	

	void draw(sf::RenderWindow& win, float clock_sample); // draws all objects on game board
	void set_object_null(sf::Vector2f place);
	void set_time(int elapsed) ; // sets game time
	void openKeyGate() const; // opens the key gate
	void CheckForCollision(Player& p) ; // checks for collisions between objects
	void CheckForMonsCollision(Player& p, vector<Knife>& m_knifes, vector<NinjaStar>& m_Nstars) ; // checks for collision betwen monsters and objects
	void handleFloating(Player& p) ; // handles player floating
	void moveMonsters(sf::Vector2f playerLoc, float clock_sample) const; // runs the move functions of monsters
	void drawMonsters(sf::RenderWindow& win, float clock_sample) const; // draws monsters
	void checkWeaponColission(vector<Knife>& m_knifes, vector<NinjaStar>& m_Nstars) ; // checks collisions between weapons and other game objects
	void set_gift(int x, int y, char icon) ; // sets gifts

	const int get_width() const; // get level width
	const int get_time() const; // get level time 
	const int get_length() const; // get level lenght 
	const int get_keys() const; // get level keys 
	const int get_diamonds() const; // get level diamonds
	const int get_levelTime() const; // get level time

	bool ObjectsCollided(Object& obj1, Object& obj2) const;
	bool isFloating(Player& p) const; // Player floating check
	bool isOnFloor(Player& p) const; // Player floor check
	bool isOnGround(Player& p) const; // Player ground check
	bool isClimbing(Player& p) const; // Player climb check
	bool isAboveLadder(Player& p) const; // Player ladder check
	const StaticObject* get_object(sf::Vector2f place) const; // returns a pointer to static objets for access purpuses

	const sf::Vector2i get_player() const; // gets player location on board


private:
	
	sf::Vector2i playerLoc; // player location on board
	int m_fallSpeed; // player fall speed
	int m_time; // curent level time
	int m_level; // number of current level.
	int m_width; // level width
	int m_length; // level lenght
	int m_keys; // number of keys in current level
	int m_diamonds; // number of diamonds in current level
	int m_levelTime; // level timer


	vector <std::unique_ptr<Monster>> m_monster; //static objects vector.
	vector <string> m_file_vector; //vector of string.
	vector <vector <std::unique_ptr<StaticObject>>> m_board; //static objects vector.

	bool knifeColided;
	bool colided;
	void copy_to_file_vector(ifstream& file) ; // loads current file to memory
	void define_m_board(vector <string> m_file_vector) ; // inserts the level file into game memory
	void make_m_board() ; // creates the game board
	sf::Vector2i m_KeyGate; // saves door location to chage the picture when all keys are found
};

