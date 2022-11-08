#pragma once

#include "Framework.h"

#include "Entity.h"

class DrawableEntity : public Entity {
private:
	Sprite* sprite;

public:
	DrawableEntity (Vec2<> position, Vec2<> size, const char* spritePath) : Entity{ position, size }, sprite{ createSprite(spritePath) } {
		resize(size);
	}

	DrawableEntity& operator=(DrawableEntity const&) = delete;
	DrawableEntity(const DrawableEntity&) = delete;

	virtual ~DrawableEntity() {
		destroySprite(sprite);
	}

	virtual void draw() const {
		drawSprite(sprite, position.x, position.y);
	}

	void resize(Vec2<> size_) {
		setSpriteSize(sprite, size_.x, size_.y);
		size = size_;
	}
};
