#pragma once

#include "Entity.h"

class Ball : public Entity {
private:
	static constexpr Vec2 defaultSize { 20, 20 };

public:
	Ball (Vec2 position, const char* spritePath) : Entity{ position, defaultSize, spritePath } {}

	void moveToMouse(Vec2 mousePos) {
		Vec2 size = getSize();
		position = { mousePos.x - size.x / 2, mousePos.y - size.y / 2 };
	}
};
