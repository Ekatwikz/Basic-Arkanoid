#include <memory>

#include "Framework.h"

typedef struct Vec2 {
	int x, y;
} Vec2;

class Entity {
protected:
	Vec2 position;

private:
	Sprite* sprite;

public:
	Entity (Vec2 position_, Vec2 size, const char* spritePath) : position{position_}, sprite{createSprite(spritePath)} {
		resize(size);
	}

	~Entity() {
		destroySprite(sprite);
	}

	void draw() {
		drawSprite(sprite, position.x, position.y);
	}

	void resize(Vec2 size) {
		setSpriteSize(sprite, size.x, size.y);
	}
};
