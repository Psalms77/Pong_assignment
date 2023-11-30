#include "PaddleAI.h"

void PaddleAI::initVariables()
{
	this->movementSpeed = 300.f;
	this->decisionTime = 5.f;
	this->timer = 0.f;
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

void PaddleAI::update(const sf::RenderTarget* target, const sf::CircleShape ball, float dt)
{
	// behaviour counter
	if (this->timer <= this->decisionTime)
	{
		this->timer += dt;
	}
	else if (this->timer > this->decisionTime)
	{
		this->rng = rand() % 10 + 1;
		if (rng > 3)
		{
			this->movementSpeed = 300.f;
		}
		else
		{
			this->movementSpeed = 70.f;
		}
		this->timer = 0.f;
	}




	//this->shape.setPosition(this->shape.getPosition().x , ball.getPosition().y - 40.f);
	if (ball.getPosition().y > this->shape.getPosition().y + 80.f)
	{
		this->shape.move(0, movementSpeed * dt);		// go down
	}
	else if (ball.getPosition().y < this->shape.getPosition().y +20.f)
	{
		this->shape.move(0, -movementSpeed * dt);		// go up
	}

}

void PaddleAI::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

