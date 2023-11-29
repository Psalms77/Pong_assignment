#include "Ball.h"




void Ball::initVariables() {
	// properties
	this->movementSpeed = 1.f;
	this->direction = sf::Vector2f(-2.f, 0.5);
}


void Ball::initShape() {
	this->shape.setRadius(15.f);
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOutlineColor(sf::Color::Green);
	this->shape.setOutlineThickness(1.f);
}

// constructors/destructors

Ball::Ball(float x, float y) {
	this->initVariables();
	this->initShape();

	this->shape.setPosition(x, y);
}

Ball::~Ball() {


}



// functions

void Ball::updatewindowboundscollision(const sf::RenderTarget* target)
{
	// bouncing off window top and bottom bounds

	sf::FloatRect ballBounds = this->shape.getGlobalBounds();

	if (ballBounds.top <= 0.f || ballBounds.top + ballBounds.height >= target->getSize().y)
	{
		this->direction.y = -this->direction.y;
	}


}

void Ball::update(const sf::RenderTarget* target) {

	this->updatewindowboundscollision(target);



	// move

	this->shape.setPosition(
		this->shape.getPosition().x + this->movementSpeed * this->direction.x,
		this->shape.getPosition().y + this->movementSpeed * this->direction.y
	);


}

void Ball::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
