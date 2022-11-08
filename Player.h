#pragma once

#include "DrawableEntity.h"

class Player : public DrawableEntity {
private:
	static constexpr Vec2 defaultSize { 200, 40 };

public:
	Player (Vec2 position, const char* spritePath) : DrawableEntity{ position, defaultSize, spritePath } {}
};
