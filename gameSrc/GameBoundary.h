#pragma once

#include "Entity.h"

// remove?
class GameBoundary : public Entity {
private:
	static constexpr Vec2<> defaultPosition { 0, 0 };

public:
	GameBoundary (Vec2<> size = {0, 0})
		: Entity{ defaultPosition, size } {}
};
