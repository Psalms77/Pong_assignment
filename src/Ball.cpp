#include "Ball.h"




void Ball::initVariables() {
	// properties
	this->movementSpeed = 5.f;
	this->direction = sf::Vector2f(1.f, 0.f);
}


void Ball::initShape() {
	this->shape.setRadius(30.f);
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



}

void Ball::update(const sf::RenderTarget* target) {

	this->updatewindowboundscollision(target);



	// move




}

void Ball::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
