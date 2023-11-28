#include "Ball.h"




void Ball::initVariables() {
	// properties
	this->movementSpeed = 1.f;

}


void Ball::initShape() {
	this->shape.setRadius(10.f);
	this->shape.setFillColor(sf::Color::White);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(1.f);
}



Ball::Ball(float x, float y) {
	this->initVariables();
	this->initShape();

	this->shape.setPosition(x, y);
}

Ball::~Ball() {

}


// accessors

const sf::FloatRect Ball::getBounds() const {
	return this->shape.getGlobalBounds();
}

const sf::Vector2f& Ball::getPos() const {
	return this->shape.getPosition();
}


// functions

void Ball::update() {
	// move
	this->shape.move(this->movementSpeed, 0.f);
}

void Ball::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
