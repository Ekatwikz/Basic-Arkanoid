#pragma once

#include "Entity.h"

class Player : public Entity {
private:
	static constexpr Vec2 defaultSize { 200, 40 };

public:
	Player (Vec2 position, const char* spritePath) : Entity{ position, defaultSize, spritePath } {}
};
