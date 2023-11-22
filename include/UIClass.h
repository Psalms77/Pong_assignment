#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "sstream"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class UIClass
{


	private:
	//variables
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;
	sf::Vector2f direction;
	float movementSpeed;
	//private functions
	void initVariables();
	void initShape();
	void initText();


	public:
		UIClass(float x, float y, std::string text);
		virtual ~UIClass();

		//accessors
		const sf::FloatRect getBounds() const;
		const sf::Vector2f& getPos() const;

		//functions
		void update();
		void render(sf::RenderTarget* target);


};

