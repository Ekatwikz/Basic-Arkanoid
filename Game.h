#pragma once

#include <vector>

#include "Player.h"
#include "Ball.h"
#include "Keyboard.h"
#include "GameBoundary.h"

class Game {
private:
	bool gameStarted;
	static Game* game;

	GameBoundary gameBoundary;
	KeyboardState keyboard;
	Vec2 mousePos;

	Player* player;
	Ball* ball;

	std::vector<DrawableEntity*> drawables;
	Game() {
		drawables.push_back(player = new Player({50, 50}, "./data/49-Breakout-Tiles.png"));
		drawables.push_back(ball = new Ball({0, 0}, "./data/63-Breakout-Tiles.png"));
	}

	~Game() {
		for (DrawableEntity* pEnt : drawables) {
			delete pEnt;
		}

		drawables.clear();
	}

public:
	Game& operator=(Game const&) = delete;
	Game(const Game&) = delete;

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
		if (!gameStarted) {
			ball->moveToMouse(mousePos);
		}

		if (!player->hasCollided(gameBoundary)) {
			*player += keyboard.getVec2() * 2;
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
		keyboard.handleKeyPress(key, isPressed);
	}

	void setSize(Vec2 size) {
		gameBoundary = { size };
	}
};

Game* Game::game;
