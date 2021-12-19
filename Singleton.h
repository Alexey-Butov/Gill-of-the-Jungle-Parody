#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class Singleton
{

public:

	static Singleton& show();
	sf::Texture* get_pic(int pic_num) ; // texture get function
	sf::Sound& get_sound(int sound_num); // sound get function

	~Singleton();

private:

	Singleton();
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	std::vector<sf::Texture> m_pics_vec; // textures vector
	sf::Sound m_music[14]; // music files array
	sf::SoundBuffer m_Sbuffer[14]; // sounds buffer array

};
