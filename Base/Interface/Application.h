#ifndef __APPLICATION_H
#define __APPLICATION_H

#include <SFML/Graphics.hpp>

#include "../World/World.h"

class Application {
	public:
		Application();
		void run();
	
	private:
		void update(sf::Time);
		void render();
		
	private:
		sf::RenderWindow window;
		static const sf::Time secondsFramesRatio;
		
		World world;
		
		sf::Sprite sprite;
		sf::Texture texture;
};

#endif