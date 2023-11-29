#include "PaddleAI.h"

void PaddleAI::initVariables()
{

}

void PaddleAI::initShape(float x, float y)
{
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(20.f, 100.f));
	//this->shape.setOrigin(this->shape.getSize() / 2.f);
	this->shape.setPosition(sf::Vector2f(x, y));
}

PaddleAI::PaddleAI(float x, float y)
{
	this->initShape(x, y);
	this->initVariables();
}

PaddleAI::~PaddleAI()
{

}

void PaddleAI::update(const sf::RenderTarget* target, const sf::CircleShape ball)
{
	this->shape.setPosition(this->shape.getPosition().x , ball.getPosition().y - 40.f);
}

void PaddleAI::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

