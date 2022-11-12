#pragma once

#include "Entity.h"
#include "WrappedSprite.h"

class DrawableEntity : public Entity {
private:
	WrappedSprite sprite;

public:
	DrawableEntity (Vec2<> position, Vec2<> size, const char* spritePath)
		: Entity{ position, size }, sprite{ spritePath } {
		resize(size);
	}

	void draw() const {
		drawSprite(&sprite, position.x, position.y);
	}

	void resize(Vec2<> size_) {
		setSpriteSize(&sprite, size_.x, size_.y);
		size = size_;
	}
};
