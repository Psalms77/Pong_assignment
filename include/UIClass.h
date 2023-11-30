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
    // start scene
	sf::Font font;
	sf::Text title;
	sf::Text onePlayer;
	sf::Text twoPlayer;
	//game scene
	sf::Text p1score;
	sf::Text p2score;
	sf::Text buttonhints;


	//private functions
	void initVariables();


	public:
		UIClass();
		virtual ~UIClass();

		//functions
		void update(sf::RenderTarget* target, int p1, int p2);
		void render(sf::RenderTarget* target, int i);


};

