#include "snake.h"
#include <SFML/Audio.hpp>

int main() {

	sf::SoundBuffer buffer;
	buffer.loadFromFile("D:\\Downloads\\killing.wav");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	snake game;

	game.start();

	return 0;
}