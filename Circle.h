#pragma once
#include "Component.h"
#include <SFML\Graphics.hpp>

class Circle : public Component {
	int x;
	int y;
	int radio;
	sf::CircleShape sprite;

protected:
	std::function <void(Event)> clickEvent() override {

	};
	std::function <void(Event)> mouseMoveEvent() override {

	};

public:
	Circle() {
		sprite.setRadius(rand() % 50);
		x = rand() % 1280;
		y = rand() % 720;
		sprite.setPosition(sf::Vector2f(x, y));
	};

	std::function <void(Event)> onClick(Windows& window) override {
		Component* newComponent = new Circle;
		window.addComponent(newComponent);
	};

	std::function <void(Event)> onMouseMove(sf::RenderWindow &window) override {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sprite.setPosition(sf::Vector2f(mousePosition.x/2, mousePosition.y/2));
	};

	void draw(sf::RenderWindow &window) override {
		window.draw(sprite);
	};
};