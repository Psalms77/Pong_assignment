#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "sstream"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Ball
{


	private:
	//variables
	sf::CircleShape shape;
	sf::Vector2f direction;
	float movementSpeed;
	//private functions
	void initVariables();
	void initShape();



	public:
		Ball(float x, float y);
		virtual ~Ball();

		//accessors
		const sf::FloatRect getBounds() const;
		const sf::Vector2f& getPos() const;

		//functions
		void update();
		void render(sf::RenderTarget* target);
};

