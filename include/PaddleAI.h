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

	int rng;
	float timer;
	float decisionTime;
	void initVariables();
	void initShape(float x, float y);




public: 
	sf::RectangleShape shape;
	float movementSpeed;

	PaddleAI(float x = 740.f, float y = 200.f);
	virtual ~PaddleAI();
	float generateRandomFloat(float min, float max);
	void update(const sf::RenderTarget* target, const sf::CircleShape ball, float dt);
	void render(sf::RenderTarget* target);



};

