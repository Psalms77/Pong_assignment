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

class Engine
{
private:
	//variables

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Font font;
	//game objects

	PlayerPaddle playerPaddle_1;
	Ball ball;

	// clock
	float dt;
	sf::Clock dtClock;



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

