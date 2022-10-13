#pragma once

#include "Singleton.h"
#include <iostream>

Singleton::Singleton() //all uploads push to vector later
{
	//change to while loop
	sf::Texture background, knife, knife2,  mnubckgrnd, jill, bill, floor, wall, playerChoose, controls, help, apple,
				wall1, wall2, KeyGate, Key, Spikes, Vines, diamond, gemgate, vine, specialWall, KeyGate2, ninjaStar, 
				monster, StatusWallpaper, Alligator, ant, bee, bird, frog, snake, gameOver, victory, levelup,
				hearts, xpB, timeB, shieldBall, shield, one, two, three, four, five;
				

	// all the pictures are loaded
	if (!background.loadFromFile("b.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!knife.loadFromFile("knife.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!mnubckgrnd.loadFromFile("menuback2.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!jill.loadFromFile("jill.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!bill.loadFromFile("bill.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!floor.loadFromFile("floor.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!playerChoose.loadFromFile("playerChoose.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!controls.loadFromFile("controls.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!help.loadFromFile("help.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!apple.loadFromFile("apple.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!wall1.loadFromFile("wall1.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!wall2.loadFromFile("wall2.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!KeyGate.loadFromFile("KeyGate.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!Key.loadFromFile("Key.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!Spikes.loadFromFile("spikes.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!Vines.loadFromFile("ladder.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!wall.loadFromFile("wall.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!diamond.loadFromFile("diamond.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!gemgate.loadFromFile("gemgate.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!specialWall.loadFromFile("ladderwall.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!KeyGate2.loadFromFile("KeyGate2.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!ninjaStar.loadFromFile("ninjaStar.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!monster.loadFromFile("monster.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!StatusWallpaper.loadFromFile("StatusWallpaper.jpg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!knife2.loadFromFile("knife2.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!Alligator.loadFromFile("Alligator.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!ant.loadFromFile("ant.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!bee.loadFromFile("bee.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!bird.loadFromFile("bird.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!frog.loadFromFile("frog.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!snake.loadFromFile("snake.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!gameOver.loadFromFile("gameOver.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!victory.loadFromFile("victory.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!levelup.loadFromFile("levelup.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!hearts.loadFromFile("hearts.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!xpB.loadFromFile("xpGift.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!timeB.loadFromFile("timeGift.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!shieldBall.loadFromFile("shieldBall.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!shield.loadFromFile("shield.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!one.loadFromFile("1.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!two.loadFromFile("2.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!three.loadFromFile("3.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!four.loadFromFile("4.png"))
		std::cout << "error cannot open picture" << std::endl;
	if (!five.loadFromFile("5.png"))
		std::cout << "error cannot open picture" << std::endl;

	// put all the pictures in a vector
	m_pics_vec.emplace_back(background);		//m_pics_vec[0]
	m_pics_vec.emplace_back(knife);				//m_pics_vec[1]
	m_pics_vec.emplace_back(mnubckgrnd);		//m_pics_vec[2]
	m_pics_vec.emplace_back(jill);				//m_pics_vec[3]
	m_pics_vec.emplace_back(bill);				//m_pics_vec[4]
	m_pics_vec.emplace_back(floor);				//m_pics_vec[5]
	m_pics_vec.emplace_back(playerChoose);      //m_pics_vec[6]
	m_pics_vec.emplace_back(controls);			//m_pics_vec[7]
	m_pics_vec.emplace_back(help);				//m_pics_vec[8]
	m_pics_vec.emplace_back(apple);				//m_pics_vec[9]
	m_pics_vec.emplace_back(wall1);				//m_pics_vec[10]
	m_pics_vec.emplace_back(wall2);				//m_pics_vec[11]
	m_pics_vec.emplace_back(KeyGate);		    //m_pics_vec[12]
	m_pics_vec.emplace_back(Key);				//m_pics_vec[13]
	m_pics_vec.emplace_back(Spikes);			//m_pics_vec[14]
	m_pics_vec.emplace_back(Vines);			    //m_pics_vec[15]
	m_pics_vec.emplace_back(wall);			    //m_pics_vec[16]
	m_pics_vec.emplace_back(diamond);			//m_pics_vec[17]
	m_pics_vec.emplace_back(gemgate);			//m_pics_vec[18]
	m_pics_vec.emplace_back(specialWall);		//m_pics_vec[19]
	m_pics_vec.emplace_back(KeyGate2);		    //m_pics_vec[20]
	m_pics_vec.emplace_back(ninjaStar);		    //m_pics_vec[21]
	m_pics_vec.emplace_back(monster);		    //m_pics_vec[22]
	m_pics_vec.emplace_back(StatusWallpaper);	//m_pics_vec[23]
	m_pics_vec.emplace_back(Alligator);		    //m_pics_vec[24]
	m_pics_vec.emplace_back(knife2);		    //m_pics_vec[25]
	m_pics_vec.emplace_back(ant);				//m_pics_vec[26]
	m_pics_vec.emplace_back(bee);				//m_pics_vec[27]
	m_pics_vec.emplace_back(bird);				//m_pics_vec[28]
	m_pics_vec.emplace_back(frog);				//m_pics_vec[29]
	m_pics_vec.emplace_back(snake);				//m_pics_vec[30]
	m_pics_vec.emplace_back(gameOver);			//m_pics_vec[31]
	m_pics_vec.emplace_back(victory);			//m_pics_vec[32]
	m_pics_vec.emplace_back(levelup);			//m_pics_vec[33]
	m_pics_vec.emplace_back(hearts);			//m_pics_vec[34] 
	m_pics_vec.emplace_back(xpB);			    //m_pics_vec[35]
	m_pics_vec.emplace_back(timeB);			    //m_pics_vec[36]
	m_pics_vec.emplace_back(shieldBall);	    //m_pics_vec[37]
	m_pics_vec.emplace_back(shield);	        //m_pics_vec[38]
	m_pics_vec.emplace_back(one);			    //m_pics_vec[39]
	m_pics_vec.emplace_back(two);	            //m_pics_vec[40]
	m_pics_vec.emplace_back(three);	            //m_pics_vec[41]
	m_pics_vec.emplace_back(four);	            //m_pics_vec[42]
	m_pics_vec.emplace_back(five);	            //m_pics_vec[43]

	m_pics_vec.at(6).setSmooth(true); // playerChoose picture settings


	//sf::SoundBuffer KunaiThrow, GameLevel, eat, FlappingWings, Shuriken, hit;


	if (!m_Sbuffer[0].loadFromFile("KunaiThrow.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[1].loadFromFile("MenuMusic.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[2].loadFromFile("eat.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[3].loadFromFile("FlappingWings.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[4].loadFromFile("Shuriken.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[5].loadFromFile("hit.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[6].loadFromFile("gift.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[7].loadFromFile("key.wav"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[8].loadFromFile("diamond.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[9].loadFromFile("gameBack.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[10].loadFromFile("jump.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[11].loadFromFile("level_end.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[12].loadFromFile("win.ogg"))
		std::cout << "error cannot open picture" << std::endl;
	if (!m_Sbuffer[13].loadFromFile("lost.ogg"))
		std::cout << "error cannot open picture" << std::endl;

	m_music[0].setBuffer(m_Sbuffer[0]);	    //m_pics_vec[0]
	m_music[1].setBuffer(m_Sbuffer[1]);		//m_pics_vec[1]
	m_music[2].setBuffer(m_Sbuffer[2]);		//m_pics_vec[2]
	m_music[3].setBuffer(m_Sbuffer[3]);		//m_pics_vec[3]
	m_music[4].setBuffer(m_Sbuffer[4]);		//m_pics_vec[4]
	m_music[5].setBuffer(m_Sbuffer[5]);		//m_pics_vec[5]
	m_music[6].setBuffer(m_Sbuffer[6]);		//m_pics_vec[6]
	m_music[7].setBuffer(m_Sbuffer[7]);		//m_pics_vec[7]
	m_music[8].setBuffer(m_Sbuffer[8]);		//m_pics_vec[8]
	m_music[9].setBuffer(m_Sbuffer[9]);		//m_pics_vec[9]
	m_music[10].setBuffer(m_Sbuffer[10]);   //m_pics_vec[10]
	m_music[11].setBuffer(m_Sbuffer[11]);   //m_pics_vec[10]
	m_music[12].setBuffer(m_Sbuffer[12]);   //m_pics_vec[10]
	m_music[13].setBuffer(m_Sbuffer[13]);   //m_pics_vec[10]

	m_music[1].setVolume(1);
}

// will make a static object to get a picture.
Singleton& Singleton::show()
{
	static Singleton noun;
	return noun;
}

// return the picture from the array.
sf::Texture* Singleton::get_pic(int pic_num) // get picture
{
	return &m_pics_vec.at(pic_num);
}


sf::Sound& Singleton::get_sound(int sound_num)  // get sound
{
	return m_music[sound_num];
}


Singleton::~Singleton()
{
}