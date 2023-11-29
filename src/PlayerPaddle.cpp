#include "PlayerPaddle.h"

void PlayerPaddle::initVariables() {

	this->movementSpeed = 10.f;

}

void PlayerPaddle::initShape(float x, float y) {
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(20.f, 100.f));
	//this->shape.setOrigin(this->shape.getSize() / 2.f);
	this->shape.setPosition(sf::Vector2f(x, y));
}


PlayerPaddle::PlayerPaddle(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape(x, y);

}

PlayerPaddle::~PlayerPaddle()
{

}

void PlayerPaddle::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->shape.move(0.f, this->movementSpeed);
	}

}

void PlayerPaddle::updateboundscollision(const sf::RenderTarget* target)
{
	// windows bounds collision
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	if (playerBounds.top <= 0.f)
	{
		this->shape.setPosition(playerBounds.left, 0.f);
	}
	if (playerBounds.top + playerBounds.height >= target->getSize().y)
	{
		this->shape.setPosition(this->shape.getPosition().x, target->getSize().y - playerBounds.height);
	}
}

void PlayerPaddle::update(const sf::RenderTarget* target)
{
	// windows bounds collision
	this->updateboundscollision(target);

	// player inputs moving up (w) or down (s)
	this->updateInput();


}



void PlayerPaddle::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}


