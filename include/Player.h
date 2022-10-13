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

	void setLocation(float newState) {};
	void setPlayer(sf::Vector2i pos, int x);
	void move(float x, float y, float dirc) override;
	void set_y_position(float y)override;
	void draw(sf::RenderWindow& window, float gameClock) ;
	void fix_position() ;
	void set_location(sf::Vector2f newp);
	void increaseScore()  { m_status.set_score(10);};
	void addKey() ;
	void setStatus(int &keys, int &diamonds) ;
	void addDiamond()  { m_status.set_diamond(1); };
	void decreaseLife()  ;
	void addLife()  { m_status.set_lives(1); };
	void addScore()  {m_status.set_score(10);};
	void addTime()  {m_status.set_time();};
	void resetKeys() ;
	void resetPosition()  { set_location(original_pos); }; // player reset position
	void setPrevPos(sf::Vector2f& prev) { prev_pos = prev;}; // player set position
	void setJump(bool x) { m_jump = x; }; // set player to jump mode
	void setClimb(bool x) { m_climb = x; }; // set player to climbing mode
	void setSield(bool x) { m_shield = x; };
	void setGatePassStatus(bool status) { m_passedInGate = status; };
	void setGemGatePassStatus(bool status) { m_passedInGemGate = status; };
	void setEnoughKeys(bool status) {m_gotEnoughKeys = status;}; // check keys
	bool getJumpStatus() const { return m_jump; };
	bool getClimbStatus() const { return m_climb; };
	bool getShieldStatus() const { return m_shield; }; // shield status
	bool getGatePassStatus() const { return m_passedInGate; };
	bool gotEnoughKeys() const { return m_gotEnoughKeys; };
	bool getGemGatePassStatus() const { return m_passedInGemGate; };
	const sf::Vector2f getPosition() const { return player_pos; }
	const sf::Vector2f get_location() const ;
	directions_t get_direction() const;
	sf::Sprite get_sprite()override { return playerSpr; };
	const int getLives() const;
	const int getKeys() const;
	int getDiamonds()  { return m_status.get_diamond(); };
	const int getDiamondsGoal() const { return m_status.get_diamond_goal(); };
	const int getKeysGoal() const { return m_status.get_key_goal(); };

protected:

	sf::RectangleShape background;
	sf::View viewStatus;
	sf::Vector2i source;
	sf::Vector2f player_pos;
	sf::Vector2f prev_pos;
	sf::Vector2f original_pos;
	sf::Sprite playerSpr;
	sf::Sprite shield;
	int m_pic;
	int m_x;
	int m_lives;
	int m_score;
	int m_keys;
	int shieldTimer = 170;
	float m_Xdistance;
	float m_Ydistance;
	StatusBar m_status;
	bool m_jump;
	bool m_climb;
	bool m_passedInGate = false;
	bool m_passedInGemGate = false;
	bool m_gotEnoughKeys = false;
	bool m_shield;
};