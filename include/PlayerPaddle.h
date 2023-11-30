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



	void initVariables();
	void initShape(float x, float y);




public:
	sf::RectangleShape shape;

	float movementSpeed;

	PlayerPaddle(float x = 40.f, float y = 200.f);
	virtual ~PlayerPaddle();

	virtual void updateInput();
	void updateboundscollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

};

