#pragma once

#include "Framework.h"

#include "DrawableEntity.h"

class MovableEntity : public DrawableEntity {
protected:
	Vec2<float> velocity;
	float speed;

public:
	MovableEntity (Vec2<> position, Vec2<> size, const char* spritePath, float speed_ = 1) : DrawableEntity{ position, size, spritePath }, speed{ speed_ } { }

	virtual void move() {
		position += velocity * speed;
	}

	virtual void moveCenterTo(const Vec2<>& pos) {
		Vec2<> size = getSize();
		position = { pos.x - size.x / 2, pos.y - size.y / 2 };
	}
};
