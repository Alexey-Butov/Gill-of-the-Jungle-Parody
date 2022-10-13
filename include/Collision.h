#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <typeinfo>
#include <typeindex>
#include "Object.h"
#include "Apple.h"
#include "Player.h"
#include "Spikes.h"
#include "Floor.h"
#include "KeyGate.h"
#include "Wall.h"
#include "Key.h"
#include "Diamond.h"
#include "GemGate.h"
#include "Vine.h"
#include "SpecialWall.h"
#include "Frog.h"
#include "Alligator.h"
#include "Ant.h"
#include "Bee.h"
#include "Bird.h"
#include "Snake.h"
#include "knife.h"
#include "NinjaStar.h"
#include "PresentLife.h"
#include "PresentScore.h"
#include "PresentTime.h"
#include "PresentShield.h"
#include <Board.h>


using HitFunctionPtr = void (*)(Object&, Object&); // pointer to functions
using typesPair = std::pair<std::type_index, std::type_index>; // pair of objects
using HitMap = std::map<typesPair, HitFunctionPtr>; // The functions map

// The Collision class represents the map of collision functions (multimethods)
class Collision
{
public:

	static Collision& instance() ;
    HitMap initializeCollisionMap() ;
	void processCollision(Object& object1, Object& object2) ;
	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2);
	~Collision() = default;

private:
	Board m_items;
	Collision() ;
	Collision(const Collision&) = delete;
	HitMap m_ObjectsMap;
	Collision& operator=(const Collision&) = delete;
};

// Global Collision Functions
void playerWall(Object& player, Object& wall) ; // player collision with a wall
void playerApple(Object& player, Object& apple) ; // player collision with an apple
void playerPresentLife(Object& player, Object& presentLife) ; // player collision with a Life Present
void playerPresentScore(Object& player, Object& presentscore) ; // player collision with a score Present
void playerPresentTime(Object& player, Object& presenttime) ; // player collision with a time Present
void playerPresentShield(Object& player, Object& presentShield) ; // player collision with a shield Present
void playerSpikes(Object& player, Object& spikes) ; // player collision with spikes
void playerKey(Object& player, Object& key) ; // player collision with a key
void playerKeyGate(Object& player, Object& keyGate) ; // player collision with a keyGate
void playerDiamond(Object& player, Object& diamond) ; // player collision with a diamond
void playerGemGate(Object& player, Object& gemgate) ; // player collision with a gem gate
void playerVine(Object& player, Object& vine) ; // player collision with a vine
void playerSpecialWall(Object& player, Object& SpecialWall) ; // player collision with a Special Wall
void playerFrog(Object& player, Object& monster) ; // player collision with a monster
void frogPlayer(Object& monster, Object& player) ; // monster collision with a player
void playerAlligator(Object& player, Object& monster) ; // player collision with a monster
void alligatorPlayer(Object& monster, Object& player) ; // monster collision with a player
void playerAnt(Object& player, Object& monster) ; // player collision with a monster
void antPlayer(Object& monster, Object& player) ; // monster collision with a player
void playerBee(Object& player, Object& monster) ; // player collision with a monster
void beePlayer(Object& monster, Object& player) ; // monster collision with a player
void playerBird(Object& player, Object& monster) ; // player collision with a monster
void birdPlayer(Object& monster, Object& player) ; // monster collision with a player
void playerSnake(Object& player, Object& monster) ; // player collision with a monster
void snakePlayer(Object& monster, Object& player) ; // monster collision with a player
void monsterItem(Object& monster, Object& player) ; // monster collision with a player
void frogWall(Object& frog, Object& wall) ; // frog collision with a wall
void antWall(Object& ant, Object& wall) ; // ant collision with a wall
void alligatorWall(Object& alligator, Object& wall) ; // alligator collision with a wall
void birdWall(Object& bird, Object& wall) ; // bird collision with a wall
void beeWall(Object& bee, Object& wall) ; // bee collision with a wall
void snakeWall(Object& snake, Object& wall) ; // snake collision with a wall
void snakeKnife(Object& snake, Object& knife) ; // snake collision with a knife
void knifeSnake(Object& knife, Object& snake) ; // knife collision with a snake
void birdFloor(Object& bird, Object& floor) ; // bird collision with a floor
void beeFloor(Object& bee, Object& floor) ; // bee collision with a floor
void snakeFloor(Object& snake, Object& floor) ; // bird collision with a floor
void alligatorFloor(Object& alligator, Object& floor) ; // bee collision with a floor
void frogFloor(Object& frog, Object& floor) ; // bird collision with a floor
void antFloor(Object& ant, Object& floor) ; // bee collision with a floor
void playerFloor(Object& player, Object& floor) ; // player collision with a floor