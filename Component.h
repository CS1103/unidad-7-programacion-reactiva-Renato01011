#pragma once
#include <functional>
#include "Event.h"

class Component {
protected:
	virtual std::function <void(Event)> clickEvent() = 0;
	virtual std::function <void(Event)> mouseMoveEvent() = 0;

public:
	virtual std::function <void(Event)> onClick(extern Windows w) = 0;
	virtual std::function <void(Event)> onMouseMove(sf::RenderWindow& window) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};