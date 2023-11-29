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
	
	//private functions
	void initVariables();
	void initShape();



	public:
		float movementSpeed;
		Ball(float x, float y);
		virtual ~Ball();



		//functions
		void updatewindowboundscollision(const sf::RenderTarget* target);
		void update(const sf::RenderTarget* target);
		void render(sf::RenderTarget* target);
};

