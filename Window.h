#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Component.h"

class Windows {
	std::vector <Component*> controls;
	sf::RenderWindow *window;

public:
	Windows() {
		window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Observer Patternn");
	};

	void run() {

		while (window->isOpen())
		{
			sf::Event event;
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window->close();
				
				if (event.type == sf::Event::MouseButtonPressed) {
					for (auto item : controls) {
						item->onMouseMove(*window);
					}
				}

				if (event.type == sf::Event::MouseMoved) {
					for (auto item : controls) {
						item->onClick(*this);
					}
				}
			}

			window->clear();

			for (auto item : controls) {
				item->draw(*window);
			};

			window->display();
		}

	};

	void addComponent(Component* cmp) {
		controls.push_back(cmp);
	};

	void removeComponent(Component* cmp) {
		controls.push_back(cmp);
	};

};