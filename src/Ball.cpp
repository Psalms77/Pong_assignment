#include "Ball.h"



void Ball::initVariables() {
	// properties
	this->reset();
	this->player1Score = 0;
	this->player2Score = 0;
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
// generate random normalized vector
sf::Vector2f Ball::generateRandomNormalizedVector()
{

	// Seed the random number generator with the current time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Generate random float values between -1 and 1 for a 2D vector
	float x = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;
	float y = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 2.0f - 1.0f;

	// Display the original vector
	std::cout << "Original Vector: (" << x << ", " << y << ")" << std::endl;

	// Calculate the magnitude of the vector
	float magnitude = std::sqrt(x * x + y * y);

	// Normalize the vector
	x /= magnitude;
	y /= magnitude;
	// Create a vector from the random values
	sf::Vector2f randomVector(x, y);
	return randomVector;
}

void Ball::reset() {
	this->shape.setPosition(400.f, 300.f);
	this->direction = generateRandomNormalizedVector();
    this->movementSpeed = 2.f;
}



void Ball::update(const sf::RenderTarget* target) {

	//this->updatewindowboundscollision(target);



	// move

	this->shape.setPosition(
		this->shape.getPosition().x + this->movementSpeed * this->direction.x,
		this->shape.getPosition().y + this->movementSpeed * this->direction.y
	);


}

void Ball::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
