#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "sstream"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class PlayerPaddle
{

private:

	sf::RectangleShape shape;

	float movementSpeed;
	void initVariables();
	void initShape(float x, float y);




public:
	PlayerPaddle(float x = 40.f, float y = 200.f);
	virtual ~PlayerPaddle();

	void updateInput();
	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};

