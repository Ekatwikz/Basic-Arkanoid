#pragma once

#include "Framework.h"
#include "Vec2.h"

#include "Collision.h"

using Collision::CollisionType;

class Entity {
protected:
	Vec2<> position;
	Vec2<> size;

public:
	Entity (Vec2<> position_ = {0, 0}, Vec2<> size_= {0, 0})
		: position{ position_ }, size{ size_ } { }

	// NB: this is a non-symmetric op!
	CollisionType hasCollided(const Entity& rhs) const {
		return Collision::edgesOfBoxWithBox(rhs.position, rhs.size, position, size);
	}
};
