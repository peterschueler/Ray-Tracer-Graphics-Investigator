#include "Application.h"

#include <iostream>

const sf::Time Application::secondsFramesRatio = sf::seconds(1.f/60.f);

Application::Application(): window(sf::VideoMode(200,200), "RayTracer"), world(), sprite(), texture() {
	texture.create(200,200);
	sprite.setTexture(texture);
}

void Application::run() {
	render();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}

void Application::update(sf::Time delta) {
}

void Application::render() {
	auto pixels = world.renderScene();

	texture.update(&pixels[0]);
	
	window.draw(sprite);
	window.display();
}