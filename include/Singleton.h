#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class Singleton
{

public:

	static Singleton& show();
	sf::Texture* get_pic(int pic_num) ;
	sf::Sound& get_sound(int sound_num);

	~Singleton();

private:

	Singleton();
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	std::vector<sf::Texture> m_pics_vec;
	sf::Sound m_music[14];
	sf::SoundBuffer m_Sbuffer[14];

};
