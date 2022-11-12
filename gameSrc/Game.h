#pragma once

#include <vector>

#include "Ball.h"
#include "Player.h"

class Game : private Entity {
private:
	bool gameStarted;
	static Game* game;

	Vec2<> mousePos;

	Player* player;
	Ball* ball;

	std::vector<DrawableEntity*> drawables;
	Game() : gameStarted { false } {
		drawables.push_back(player = new Player({50, 50}, "./data/49-Breakout-Tiles.png"));
		drawables.push_back(ball = new Ball({0, 0}, "./data/63-Breakout-Tiles.png"));
	}

public:
	Game& operator=(Game const&) = delete;
	Game(const Game&) = delete;

	~Game() {
		for (DrawableEntity* pEnt : drawables) {
			delete pEnt;
		}

		drawables.clear();
	}

	static Game* getGame() {
		if (!game) { [[ unlikely ]]
			game = new Game();
		}

		return game;
	}

	void setMousePos(int x, int y) {
		mousePos = { x, y };
	}

	void render() {
		player->setVelocity(this->edgesCollided(*player));
		player->move();

		if (!gameStarted) {
			ball->moveCenterTo(mousePos);
		} else {
			gameStarted = ball->setVelocity(this->edgesCollided(*ball), player->edgesCollided(*ball));
			ball->move();
		}

		for (DrawableEntity* pEnt : drawables) {
			pEnt->draw();
		}
	}

	void handleClick(FRMouseButton button, bool isReleased) {
		if (!gameStarted) {
			gameStarted = true;
		}
	}

	void handleKeyPress(FRKey key, bool isPressed) {
		player->updateKeyboard(key, isPressed);
	}

	void setSize(Vec2<> size_) {
		size = size_;
		player->moveCenterTo({ size_.x / 2, static_cast<int>(size_.y * 0.85F) });
	}
};

Game* Game::game;
