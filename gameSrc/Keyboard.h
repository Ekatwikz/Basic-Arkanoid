#pragma once

#include "../lib/Framework.h"
#include "Vec2.h"

class KeyPair {
private:
	int keyStates[2], direction = 0;

public:
	enum PossibleKeyState { UNPRESSED, PRESSED, STANDBY = -1 };
	enum Direction { FIRST = -1, NONE, SECOND };

	void setPressed(bool pos, bool state) {
		// switch state of other position
		int* other = &keyStates[!pos];
		if ((state == PRESSED && *other == PRESSED)
				|| (state == UNPRESSED && *other == STANDBY)) {
			*other *= -1;
		}

		// set state of given position
		keyStates[pos] = state;

		// update direction
		direction = 0;
		if (keyStates[0] == PRESSED) {
			direction = -1;
		} else if (keyStates[1] == PRESSED) {
			direction = 1;
		}
	}

	[[ nodiscard ]] Direction getDirection() const {
		return static_cast<Direction>(direction);
	}
};

class KeyboardState {
private:
	KeyPair leftRight, upDown;
	enum { KB_LEFT, KB_RIGHT };
	enum { KB_UP, KB_DOWN };

public: 
	void handleKeyPress(FRKey key, bool isPressed) {
		switch (key) {
			case FRKey::LEFT:
				leftRight.setPressed(KB_LEFT, isPressed);
				break;
			case FRKey::RIGHT:
				leftRight.setPressed(KB_RIGHT, isPressed);
				break;
			case FRKey::UP:
				upDown.setPressed(KB_UP, isPressed);
				break;
			case FRKey::DOWN:
				upDown.setPressed(KB_DOWN, isPressed);
				break;
			default: // ??
				break;
		}
	}

	[[ nodiscard ]] Vec2<> getVec2() const {
		return { leftRight.getDirection(), upDown.getDirection() };
	}
};
