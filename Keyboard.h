#pragma once

#include "Framework.h"

#include "Vec2.h"

typedef struct KeyPair {
	int keyStates[2];
	enum PossibleKeyStates { UNPRESSED, PRESSED, STANDBY = -1 };

	void setPressed(bool pos, int state) {
		// switch state of other position
		int oldOther = keyStates[!pos];
		if ((state == PRESSED && oldOther == PRESSED) || (state == UNPRESSED && oldOther == STANDBY)) {
			keyStates[!pos] *= -1;
		}

		// set state of this position
		keyStates[pos] = state;
	}

	int operator[](int pos) const {
		return keyStates[pos];
	}
} KeyPair;


class KeyboardState {
private:
	KeyPair leftRight, upDown;
	enum { KB_LEFT, KB_RIGHT };
	enum { KB_UP, KB_DOWN };

	Vec2 vec;

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

		vec = { 0, 0 };
		if (leftRight[KB_LEFT] == KeyPair::PRESSED) {
			vec.x = -1;
		} else if (leftRight[KB_RIGHT] == KeyPair::PRESSED) {
			vec.x = 1;
		}

		if (upDown[KB_UP] == KeyPair::PRESSED) {
			vec.y = -1;
		} else if (upDown[KB_DOWN] == KeyPair::PRESSED) {
			vec.y = 1;
		}
	}

	[[ nodiscard ]] Vec2 getVec2() const {
		return vec;
	}
};
