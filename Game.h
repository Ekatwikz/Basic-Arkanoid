#pragma once

#include <vector>

#include "Player.h"
#include "Ball.h"
#include "Keyboard.h"

#include <iostream> //tmp

class Game {
private:
	static Game* game;

	Player* player;
	KeyboardState keyboard;
	Vec2 mousePos;

	Ball* ball;

	std::vector<Entity*> entities;
	Game() {
		entities.push_back(player = new Player({50, 50}, "./data/49-Breakout-Tiles.png"));
		entities.push_back(ball = new Ball({0, 0}, "./data/63-Breakout-Tiles.png"));
	}

	~Game() {
		for (Entity* pEnt : entities) {
			delete pEnt;
		}

		entities.clear();
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
		ball->moveToMouse(mousePos); // should be if game didn't start
		*player += keyboard.getVec2() * 2;

		for (Entity* pEnt : entities) {
			pEnt->draw();
		}
	}

	void handleKeyPress(FRKey key, bool isPressed) {
		keyboard.handleKeyPress(key, isPressed);
	}
};

Game* Game::game;
