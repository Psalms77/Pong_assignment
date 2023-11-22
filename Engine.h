#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "sstream"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


class Engine
{
private:
	//variables

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;

	float dt;
	sf::Clock dtClock;
	sf::Font font;


	//window
	sf::RenderWindow* window;
	sf::Event ev;
	// private functions
	void initVariables();
	void initWindow();



public:
	Engine();
	virtual ~Engine();
	const bool isRunning() const;

	//functions
	void pollEvents();
	void update();
	void render();
};

