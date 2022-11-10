#pragma once

#include "Framework.h"

#include "DrawableEntity.h"

class MovableEntity : public DrawableEntity {
protected:
	float speed;
	Vec2<float> velocity;

	// convenient xd
	MovableEntity& operator+=(const Vec2<>& vec) {
		position += vec;
		return *this;
	}

public:
	MovableEntity (Vec2<> position, Vec2<> size, const char* spritePath, float speed_ = 1, Vec2<float> velocity_ = {0, 0})
		: DrawableEntity{ position, size, spritePath }, speed{ speed_ }, velocity{ velocity_ } { }

	virtual void move() {
		position += velocity * speed;
	}

	virtual void moveCenterTo(const Vec2<>& pos) {
		position = { pos.x - size.x / 2, pos.y - size.y / 2 };
	}
};
