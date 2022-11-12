#pragma once

#include "../lib/Framework.h"
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

	// NB: this isn't a symmetric op!
	[[ nodiscard ]] CollisionType edgesCollided(const Entity& rhs) const {
		return Collision::edgesOfRectIntersectRect(position, size, rhs.position, rhs.size);
	}
};
