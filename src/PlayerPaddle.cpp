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
void PlayerPaddle::update(sf::RenderTarget* target)
{
	// windows bounds collision
	//target->getSize;





	// player inputs moving up (w) or down (s)
	this->updateInput();


}



void PlayerPaddle::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
