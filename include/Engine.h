#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "sstream"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Ball.h>
#include <Paddle.h>
#include <PlayerPaddle.h>
#include <PaddleAI.h>
#include <PlayerPaddle_2.h>
#include <UIClass.h>

class Engine
{
private:
	//variables

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;

	bool isSinglePlayer;
	bool isMultiPlayer;
	bool isStartScene;
	bool isPaused;

	float prePauseBallSpeed;


	sf::Font font;
	//game objects

	PlayerPaddle playerPaddle_1;
	PlayerPaddle_2 playerPaddle_2;
	PaddleAI paddleAI;
	Ball ball;

	// clock
	float dt;
	sf::Clock dtClock;

	// ui
	UIClass ui;


	//window
	sf::RenderWindow* window;
	sf::Event ev;
	// private functions
	void initVariables();
	void initWindow();
	bool paddleBallCollision(const sf::CircleShape& ball, const sf::RectangleShape& paddle);


public:
	Engine();
	virtual ~Engine();
	const bool isRunning() const;

	//functions
	void pollEvents();
	void update();
	void render();
};

