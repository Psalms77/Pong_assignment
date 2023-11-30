#include "UIClass.h"



void UIClass::initVariables()
{
	this->font.loadFromFile(".\\font\\Roboto-Black.ttf");
	this->title.setFont(this->font);
	this->title.setCharacterSize(72);
	this->title.setFillColor(sf::Color::White);
	this->title.setString("PONG");
	this->title.setPosition(sf::Vector2f(300.f, 200.f));
	this->title.setOutlineColor(sf::Color::Red);
	this->title.setOutlineThickness(1.f);
	this->title.setStyle(sf::Text::Bold);

	this->onePlayer.setFont(this->font);
	this->onePlayer.setCharacterSize(20);
	this->onePlayer.setFillColor(sf::Color::White);
	this->onePlayer.setString("Press 1 => vs. AI");
	this->onePlayer.setPosition(sf::Vector2f(200.f, 400.f));

	this->twoPlayer.setFont(this->font);
	this->twoPlayer.setCharacterSize(20);
	this->twoPlayer.setFillColor(sf::Color::White);
	this->twoPlayer.setString("Press 2 => vs. Player");
	this->twoPlayer.setPosition(sf::Vector2f(500.f, 400.f));


	this->p1score.setFont(this->font);
	this->p1score.setCharacterSize(20);
	this->p1score.setFillColor(sf::Color::White);
	this->p1score.setString("Player 1: 0");
	this->p1score.setPosition(sf::Vector2f(200.f, 20.f));

	this->p2score.setFont(this->font);
	this->p2score.setCharacterSize(20);
	this->p2score.setFillColor(sf::Color::White);
	this->p2score.setString("Player 2: 0");
	this->p2score.setPosition(sf::Vector2f(500.f, 20.f));


}

UIClass::UIClass()
{
	this->initVariables();
}

UIClass::~UIClass()
{
}

void UIClass::update(sf::RenderTarget* target, int p1, int p2)
{
	this->p1score.setString("Player 1: " + std::to_string(p1));
	this->p2score.setString("Player 2: " + std::to_string(p2));

}

void UIClass::render(sf::RenderTarget* target, int i)
{
	
	if (i == 0)
	{
		target->draw(this->title);
		target->draw(this->onePlayer);
		target->draw(this->twoPlayer);
	}
	else
	{
		target->draw(this->p1score);
		target->draw(this->p2score);	
	}




}


