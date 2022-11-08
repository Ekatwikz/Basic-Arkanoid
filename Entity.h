#pragma once

#include "Framework.h"

#include "Vec2.h"

class Entity {
protected:
	Vec2 position;

private:
	Sprite* sprite;

public:
	Entity (Vec2 position_, Vec2 size, const char* spritePath) : position{ position_ }, sprite{ createSprite(spritePath) } {
		resize(size);
	}

	~Entity() {
		destroySprite(sprite);
	}

	void draw() const {
		drawSprite(sprite, position.x, position.y);
	}

	void resize(Vec2 size) {
		setSpriteSize(sprite, size.x, size.y);
	}

	void setPos(Vec2 position_) {
		position = position_;
	}

	[[ nodiscard ]] Vec2 getSize() const {
		Vec2 pos = {};
		getSpriteSize(sprite, pos.x, pos.y);
		return pos;
	}

	Entity& operator+=(Vec2 vec) {
		position += vec;
		return *this;
	}
};
