#pragma once

#include "../lib/Framework.h"

// custom copy/move semantics means single responsibility?
// also, RAII?
// idk maybe there's a better way to think about this
class WrappedSprite {
private:
	Sprite* sprite;

public:
	WrappedSprite(const char* spritePath)
		: sprite { createSprite(spritePath) } { }

	~WrappedSprite() {
		destroySprite(sprite);
	}

	[[ nodiscard ]] Sprite* operator&() const {
		return sprite;
	}

	WrappedSprite& operator=(const WrappedSprite&) = delete;
	WrappedSprite(const WrappedSprite&) = delete;

	// TODO: these shouldn't be deleted
	WrappedSprite& operator=(WrappedSprite&&) = delete;
	WrappedSprite(WrappedSprite&&) = delete;
};
