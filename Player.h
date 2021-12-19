#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> 
#include <stdlib.h>
#include <string>
#include <vector>
#include "StatusBar.h"
#include "singleton.h"
#include "DynamicObject.h"

class Player : public DynamicObject
{

public:

	//----Constructor for player object------
	Player();
	~Player() = default;

	void setLocation(float newState) {}; // sets player location
	void setPlayer(sf::Vector2i pos, int x); // sets player position
	void move(float x, float y, float dirc) override; // player movement
	void set_y_position(float y)override; // player y position
	void draw(sf::RenderWindow& window, float gameClock) ; //player draw
	void fix_position() ; // fixes player position
	void set_location(sf::Vector2f newp); // sets player location
	void increaseScore()  { m_status.set_score(10);}; // increases player score
	void addKey() ; // adds owned keys to player
	void setStatus(int &keys, int &diamonds) ; // gets player status
	void addDiamond()  { m_status.set_diamond(1); }; // adds diamonds to player
	void decreaseLife()  ; // decreases player lives
	void addLife()  { m_status.set_lives(1); }; // adds lives to player
	void addScore()  {m_status.set_score(10);}; // adds score to player
	void addTime()  {m_status.set_time();}; // adds time to player
	void resetKeys() ; // resets owned keys by player
	void resetPosition()  { set_location(original_pos); }; // player reset position
	void setPrevPos(sf::Vector2f& prev) { prev_pos = prev;}; // player set position
	void setJump(bool x) { m_jump = x; }; // set player to jump mode
	void setClimb(bool x) { m_climb = x; }; // set player to climbing mode
	void setSield(bool x) { m_shield = x; }; // sets a shield for the player
	void setGatePassStatus(bool status) { m_passedInGate = status; }; // sets key gate pass status
	void setGemGatePassStatus(bool status) { m_passedInGemGate = status; }; // sets gem gate pass status 
	void setEnoughKeys(bool status) {m_gotEnoughKeys = status;}; // check keys
	bool getJumpStatus() const { return m_jump; }; // gets jump status
	bool getClimbStatus() const { return m_climb; }; // gets climb status
	bool getShieldStatus() const { return m_shield; }; // shield status
	bool getGatePassStatus() const { return m_passedInGate; }; // gets key gate pass status
	bool gotEnoughKeys() const { return m_gotEnoughKeys; };  // gets keys status
	bool getGemGatePassStatus() const { return m_passedInGemGate; }; // gets gem gate pass status
	const sf::Vector2f getPosition() const { return player_pos; } // gets player position
	const sf::Vector2f get_location() const ; // gets player location
	directions_t get_direction() const; // gets directions enum
	sf::Sprite get_sprite()override { return playerSpr; }; // gets player picture
	const int getLives() const; // get player lives
	const int getKeys() const; // gets player keys
	int getDiamonds()  { return m_status.get_diamond(); }; // gets player diamonds
	const int getDiamondsGoal() const { return m_status.get_diamond_goal(); }; // gets diamonds goal number
	const int getKeysGoal() const { return m_status.get_key_goal(); }; // gets keys goal number

protected:

	sf::RectangleShape background; // back ground
	sf::View viewStatus; // view 
	sf::Vector2i source; // source member
	sf::Vector2f player_pos; // position member
	sf::Vector2f prev_pos; // prev position member
	sf::Vector2f original_pos; // original position member
	sf::Sprite playerSpr; // player picture
	sf::Sprite shield; // shield picture
	int m_pic; // picture
	int m_x; // x location
	int m_lives; // lives value
	int m_score; // score value
	int m_keys; // num of keys
	int shieldTimer = 170;
	float m_Xdistance; // floating on x 
	float m_Ydistance; // floating on y
	StatusBar m_status; // status bar member
	bool m_jump; // jump status
	bool m_climb; // climb status
	bool m_passedInGate = false; // key gate pass status
	bool m_passedInGemGate = false; // gem gate pass status
	bool m_gotEnoughKeys = false; // keys status
	bool m_shield; // shield status
};