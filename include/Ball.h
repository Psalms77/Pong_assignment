#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "sstream"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>




class Ball
{


	private:

	
	//private functions
	void initVariables();
	void initShape();



	public:
		//variables
		sf::CircleShape shape;
		sf::Vector2f direction;
		int player1Score;
		int player2Score;
		float movementSpeed;
		Ball(float x = 400, float y = 300);
		virtual ~Ball();



		//functions
		void reset();
		sf::Vector2f generateRandomNormalizedVector();

		void update(const sf::RenderTarget* target);
		void render(sf::RenderTarget* target);
};

