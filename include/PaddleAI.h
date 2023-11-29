#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "sstream"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class PaddleAI
{
private:


	void initVariables();
	void initShape(float x, float y);




public: 
	sf::RectangleShape shape;
	float movementSpeed;

	PaddleAI(float x = 740.f, float y = 200.f);
	virtual ~PaddleAI();

	void update(const sf::RenderTarget* target, const sf::CircleShape ball);
	void render(sf::RenderTarget* target);



};
