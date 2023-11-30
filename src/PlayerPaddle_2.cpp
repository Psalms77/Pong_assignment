#include "PlayerPaddle_2.h"


void PlayerPaddle_2::initVariables() {

	this->movementSpeed = 10.f;

}

void PlayerPaddle_2::initShape(float x, float y) {
	this->shape.setFillColor(sf::Color::White);
	this->shape.setSize(sf::Vector2f(20.f, 100.f));
	//this->shape.setOrigin(this->shape.getSize() / 2.f);
	this->shape.setPosition(sf::Vector2f(x, y));
}


PlayerPaddle_2::PlayerPaddle_2(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape(x, y);

}

PlayerPaddle_2::~PlayerPaddle_2()
{

}

void PlayerPaddle_2::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		this->shape.move(0.f, this->movementSpeed);
	}

}

void PlayerPaddle_2::updateboundscollision(const sf::RenderTarget* target)
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

void PlayerPaddle_2::update(const sf::RenderTarget* target)
{
	// windows bounds collision
	this->updateboundscollision(target);

	// player inputs moving up (w) or down (s)
	this->updateInput();


}



void PlayerPaddle_2::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}