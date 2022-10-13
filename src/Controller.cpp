#pragma once

#include "Controller.h"


//--------------------Constructor for Controller---------------------
Controller::Controller(): m_pic(ZERO), m_jumping(false), m_direction(Up)
{
	m_knifeSound = Singleton::show().get_sound(ZERO);
	m_ninjaStarSound = Singleton::show().get_sound(FOUR);
	gifts_loc = { NEGONE, NEGONE};
}

//---------Main run function for to start the game---------
void Controller::run(float width, float height, int choice) 
{
	bool moving = false, moveMonster = false;
	float clock_sample = ZERO, gameClock = ZERO;
	int lastLevel = FIVE;
	sf::View view;
	sf::Event event;
	sf::Clock clock;
	setGame();

	for (int level_num = 1; level_num <= lastLevel ; level_num++)
	{
		sf::RenderWindow m_window(sf::VideoMode(width, height), "JILL OF THE JUNGLE");
		background[level_num - ONE].setSize(sf::Vector2f(m_window.getSize().x * TEN, m_window.getSize().y));
		sf::Vector2f screen_focus1((float)m_window.getSize().x / TWO, (float)m_window.getSize().y / TWO);
		m_window.setFramerateLimit(TWENTY);

		view.reset(sf::FloatRect((float)ZERO, (float)ZERO, (float)m_window.getSize().x, (float)m_window.getSize().y));
		view.setViewport(sf::FloatRect(0.0f, 0.f, 1.0f, 1.0f));

		Board level(level_num); //create level.
		setLevel(choice, level_num, level);


		while (m_window.isOpen() && player.getLives() != ZERO)
		{

			gameClock = game_clock.getElapsedTime().asSeconds();
			gameClock = level.get_levelTime() - gameClock;

			if (gameClock < ONE)
			{
				player.decreaseLife();
				player.resetPosition();
				gameClock = level.get_levelTime();
				game_clock.restart();
			}

			while (m_window.pollEvent(event))
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					m_window.close();
					return;
				}
				if (event.type == sf::Event::KeyReleased)
				{
					player.setJump(false);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_direction = Right;
				jump(m_window, background[level_num - ONE], screen_focus1, view, POINTTHIRYFIVE, event, level, clock_sample, gameClock, level_num);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_direction = Left;
				jump(m_window, background[level_num - ONE], screen_focus1, view, NEGPOINTTHIRYFIVE, event, level, clock_sample, gameClock, level_num);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				jump(m_window, background[level_num - ONE], screen_focus1, view, ZERO, event, level, clock_sample, gameClock, level_num);

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_direction = Left;
				moving = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_direction = Right;
				moving = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (player.getClimbStatus())
				{
					m_direction = Up;
					moving = true;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if ((!level.isOnFloor(player)) || level.isAboveLadder(player))
				{
					player.setClimb(true);
					m_direction = Down;
					moving = true;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				m_knifeSound.play();
				Knife k(player);
				m_knife = true;
				k.set_pos(player);
				k.set_dirc(m_direction);
				m_knifes.emplace_back(k);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::X) ||
				sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				m_ninjaStarSound.play();
				NinjaStar n(player);
				m_knife = true;
				n.set_pos(player);
				n.set_dirc(m_direction);
				m_Nstars.emplace_back(n);
			}

			if (moveMonster)
			{
				level.moveMonsters(player.getPosition(), clock_sample);
				level.CheckForMonsCollision(player, m_knifes, m_Nstars);
			}

			if (moving)
			{
				moveMonster = true;
				clock_sample = clock.getElapsedTime().asSeconds();	//update the counter.
				move(POINTTHIRYFIVE, POINTTHIRYFIVE, level, moving, m_direction, distance(clock_sample));


				moving = false;
			}
			m_lvlDone = player.getGatePassStatus();
			if (m_lvlDone)
			{
				if(level_num == lastLevel)
				{
					setGameLevels(m_window, view, TWELVE, THIRTYTWO);
					break;
				}
	
				player.resetKeys();
				m_lvlDone = false;
				player.setGatePassStatus(false);
				player.setGatePassStatus(false);
				player.setEnoughKeys(false);
				level.openKeyGate();
				setGameLevels(m_window, view, ELEVEN, THIRTYTHREE);
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //skip level
			{
				break;
			}
			if (player.getLives() == ZERO)
			{
				setGameLevels(m_window, view, THIRTEEN, THIRTYONE);
				return;
			}
			isClimb(level, player);
			draw(m_window, background[level_num - ONE], screen_focus1, view, level, clock_sample, gameClock);
			gifts(if_points, if_stone, if_clock, clock_sample, level); //check for gifts.
			clock.restart(); //restart the clock.
			gift_status(if_points, if_stone, if_clock, clock_sample, level); //check the gifts status.
			isKnife(level, m_window, clock_sample);		
			m_window.display();
		}
	}
}

	
//---------------------------------------draw function of all objects------------------------------------------------

void Controller::draw(sf::RenderWindow& window, sf::RectangleShape& rec, sf::Vector2f& screen_focus1, sf::View& view,
	Board& level, float clock_sample, float GameClock)
{
	window.clear();
	sf::Vector2f jill_pos = player.getPosition();

	jill_pos.x = jill_pos.x * SHAPE + TO_CENTER;
	jill_pos.y = jill_pos.y * SHAPE + TO_CENTER;

	if (jill_pos.x + TEN > window.getSize().x / TWO) // set screen focus on player
		jill_pos.x = screen_focus1.x  =  jill_pos.x + TEN;
	else 
		jill_pos.x = screen_focus1.x = (float)window.getSize().x / TWO;

	
	view.setCenter(screen_focus1);
	window.setView(view);
	window.draw(rec);
	level.draw(window, clock_sample);
	level.drawMonsters(window, clock_sample);
	player.draw(window, GameClock);
}

//sets up the background and level music
void Controller::setGame() 
{
	menuMusic = Singleton::show().get_sound(NINE);

	menuMusic.setLoop(true);
	menuMusic.setVolume(TWO);
	menuMusic.play();

	for (int i = ZERO; i < FIVE; i++)
	{
		background[i].setTexture(Singleton::show().get_pic(STARTPIC + i));
		background[i].setPosition(ZERO, ZERO);
	}
	background[FIVE].setTexture(Singleton::show().get_pic(THIRTYTWO)); //victory
	background[FIVE].setPosition(ZERO, ZERO);
	background[SIX].setTexture(Singleton::show().get_pic(THIRTYTHREE)); //levelup
	background[SIX].setPosition(ZERO, ZERO);
	background[SEVEN].setTexture(Singleton::show().get_pic(THIRTYONE)); //gameover
	background[SEVEN].setPosition(ZERO, ZERO);
}

//-------------------------------function that utilizes the jump of the player-----------------------------------
void Controller::jump(sf::RenderWindow& window, sf::RectangleShape& rec, sf::Vector2f& screen_focus1, sf::View& view,
	 float x, sf::Event &event, Board& level, float clock_sample, float gameClock , int level_num) 
{
	Singleton::show().get_sound(TEN).play();
	player.setClimb(false);
	bool moving = true;
	m_jumping = true;
	player.setJump(true);
	m_velocityX = x;
	m_velocityY = MINUSTHIRTY;

	while (m_jumping)
	{	
		while (window.pollEvent(event))
		{
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				m_knifeSound.play();
				Knife k(player);
				m_knife = true;
				k.set_pos(player);
				k.set_dirc(m_direction);
				m_knifes.emplace_back(k);
				break;
		    }
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			{
				m_ninjaStarSound.play();
				NinjaStar n(player);
				m_knife = true;
				n.set_pos(player);
				n.set_dirc(m_direction);
				m_Nstars.emplace_back(n);
				break;
			}
		}
		if (!player.getJumpStatus())
		{
			m_jumping = false;
			break;
		}
		if (level.isOnGround(player) && m_velocityY > ZERO)
		{
			player.set_y_position((int)player.getPosition().y + ONE);
			m_jumping = false;
			break;
		}

		if (m_y < GROUNDLEVEL) //If you are above ground
			m_velocityY += m_gravity;//Add gravity
		if(x == ZERO)
            m_direction = m_direction;
		if(x == POINTTHIRYFIVE)
			m_direction = Right;
		if(x == NEGPOINTTHIRYFIVE)
			m_direction = Left;

		m_x += m_velocityX;
		m_y += m_velocityY;

		move(m_velocityX, m_velocityY, level, moving, m_direction, ZERO); 
		draw(window, background[level_num - ONE], screen_focus1, view, level, clock_sample, gameClock);

		if (!m_knifes.empty())
		{
			knifeMode(level);
			for (int i = ZERO; i < m_knifes.size(); i++)
				m_knifes[i].draw(window, clock_sample);
		}
		if (!m_Nstars.empty())
		{
			starMode(level);
			for (int i = ZERO; i < m_Nstars.size(); i++)
				m_Nstars[i].draw(window, clock_sample);
		}

		window.display();
		if (player.getPosition().y > EIGHTPOINTFIVE && m_velocityY > ZERO)
		{
			player.set_y_position(NINE); //change to floorHeight member
			player.setJump(false);
			m_jumping = false;
		}
	}	
	player.setJump(false);
}

//-------sets the knives in the game-------------
void Controller::knifeMode(Board& level) 
{	
	level.checkWeaponColission(m_knifes, m_Nstars);
	for (int i = ZERO; i < m_knifes.size(); i++)
	{
		m_knifes[i].move(ZERO, ZERO, ZERO);
		m_knifes[i].set_distance();
		if (m_knifes[i].get_distance() == ZERO)
		{
			m_knifes.erase(m_knifes.begin() + i);
		}
	}
}

//-------sets the stars in the game-------------
void Controller::starMode(Board& level) 
{
	level.checkWeaponColission(m_knifes, m_Nstars);
	for (int i = ZERO; i < m_Nstars.size(); i++)
	{
		m_Nstars[i].move(ZERO, ZERO, ZERO);
		m_Nstars[i].set_distance();

		if (m_Nstars[i].get_distance() == ZERO)
		{
			m_Nstars.erase(m_Nstars.begin() + i);
		}
	}
}

//do the move for the dynamic objects and check for colides.
void Controller::move(float distance_x, float distance_y, Board& level, bool move, float dirc, float clock_sample) 
{
	
	if(move)
	{	
		level.moveMonsters(player.getPosition(), clock_sample);
		level.CheckForCollision(player);
		sf::Vector2f player_prev = player.getPosition(); // the current location of object.

		player.setPrevPos(player_prev);
		if(m_jumping)
		{
			 player.move(distance_x, distance_y, dirc);
		}
		else if (m_direction == Left)
			player.move(-distance_x, distance_y, m_direction);	//move the player.
		else
			player.move(distance_x, distance_y, m_direction);	//move the player.

	}
}


//calculate the distance that the player should go.
float Controller::distance(float clock_sample) const
{
	float distance = clock_sample * HUNDREDFIFTY; // player distance by clock;
	return distance;
}


// will lottery a special gift (only one on the board each time).
void Controller::gifts(bool& if_points, bool& if_stone, bool& if_clock, float clock_sample, Board& level) 
{
	sf::Vector2f location = { FORTYFIVE, FORTYFIVE }; // set the location.
	int x, y;
	char icon{};

	m_gifts_counter += clock_sample; //update the special gift counter.

	//check if its time for new gift and if there is no other gift on the board.
	if (m_gifts_counter >= FIVE && gifts_loc.x == NEGONE && gifts_loc.y == NEGONE)
	{
		x = rand() % level.get_width(); //randomize for x  location
		y = rand() % level.get_length() % EIGHT + TWO; //randomize for y  location

		location.x = x;
		location.y = y;
		std::cout << "1\n";
		if(level.get_object(location) == nullptr) //search for a null place.
		{
			if (x % FOUR == ZERO) //randomize the type.
			{
				icon = '1';
				if_points = true;
				m_gift_clock = ZERO;
			}
			else if (x % FOUR == ONE)
			{
				icon = '2';
				if_stone = true;
				m_gift_clock = ZERO;
			}
			else if (x % FOUR == TWO)
			{
				icon = '3';
				if_clock = true;
				m_gift_clock = ZERO;
			}
			else if (x % FOUR == THREE)
			{
				icon = '4';
 
				if_clock = true;
				m_gift_clock = ZERO;
			}
			level.set_gift(x, y, icon); //create the gift.
			m_gifts_counter = ZERO;
			gifts_loc = location; //update the special gift location.
		}
	}
}

//check if its time to erase the items (if exist - by the boolian)
//then the funcion erase the item 
void Controller::gift_status(bool& if_points, bool& if_stone, bool& if_clock, float clock_sample, Board& level) 
{
	m_gift_clock += clock_sample; //increase the m_diamond_clock by the clock sample.

	if (if_points && m_gift_clock >= 5.f) //if points on the board;
	{
		if_points = false; //turn it to false.
		m_gift_clock = ZERO;

		level.set_object_null(gifts_loc); //erase the gift.
		gifts_loc = { NEGONE, NEGONE }; //restart the location of the gift
	}

	if (if_stone && m_gift_clock >= 5.f) //if stone on the board(same like above)
	{
		if_stone = false;
		m_gift_clock = ZERO;

		level.set_object_null(gifts_loc);
		gifts_loc = { NEGONE, NEGONE };
	}

	if (if_clock && m_gift_clock >= 5.f) //if clock on the board(same like above)
	{
		if_clock = false;
		m_gift_clock = ZERO;
		level.set_object_null(gifts_loc);
		gifts_loc = { NEGONE, NEGONE };
	}
}

//sets the game level
void Controller::setLevel(int& playerChoose, int& levelNum, Board& level) 
{
	sf::Vector2i player_pos = level.get_player();

	int keys = level.get_keys();
	int diamonds = level.get_diamonds();

	player.setStatus(keys, diamonds);
	player.setPlayer(player_pos, playerChoose);
	player.resetKeys();

	m_gifts_counter = ZERO; //count the time until we will create existing gifts.
	m_gift_clock = ZERO;	//count the time until the gifts will disappear.
	gifts_loc = { NEGONE, NEGONE }; //update the gift to "null".
}

// sets screen focus of screen view every time the level will change
// to the next level, or if the game ends, and it shows the sprite of the game 
// over the background picture and plays the level music.
void Controller::setGameLevels(sf::RenderWindow& window, sf::View& v, int x, int y) 
{
	menuMusic.stop();
	Singleton::show().get_sound(x).play();
	sf::Vector2f screen_focus1((float)window.getSize().x / TWO, (float)window.getSize().y / TWO);
	v.reset(sf::FloatRect((float)ZERO, (float)ZERO, (float)window.getSize().x, (float)window.getSize().y));
	v.setViewport(sf::FloatRect(0.0f, 0.f, 1.0f, 1.0f));
	v.setCenter(screen_focus1);
	window.setView(v);

	sf::Sprite geT;

	geT.setTexture(*Singleton::show().get_pic(y));
	geT.setTextureRect(sf::IntRect(ZERO, ZERO, LEVELWIDTH, LEVELHEIGHT));
	window.draw(geT); //show the trophy.
	window.display();
	Sleep(SLEEPSCREEN);

	window.close();
}

//checks if it is a knife
void Controller::isKnife(Board& level, sf::RenderWindow& window, float& clockSample) 
{
	if (!m_knifes.empty())
	{
		knifeMode(level);

		for (auto& item : m_knifes)
			item.draw(window, clockSample);
	}
	if (!m_Nstars.empty())
	{
		starMode(level);

		for (auto& item2 : m_Nstars)
			item2.draw(window, clockSample);
	}
}

//sets the climb
void Controller::isClimb(Board& level, Player& player) const
{
	if (!level.isFloating(player))
	{
		level.handleFloating(player);
	}
	if (level.isClimbing(player) && player.getClimbStatus())
	{
		player.setClimb(false);
	}
	if (player.gotEnoughKeys())
	{
		level.openKeyGate();
		player.setEnoughKeys(false);
	}
}

