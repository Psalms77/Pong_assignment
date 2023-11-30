#include "Engine.h"

//	init
void Engine::initVariables() {

	// init basic
	dt = 0.f;

	this->window = nullptr;
}
void Engine::initWindow() {



	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "PONG");
	this->window->setFramerateLimit(60);

}

bool Engine::paddleBallCollision(const sf::CircleShape& ball, const sf::RectangleShape& paddle)
{
	sf::FloatRect ballBounds = ball.getGlobalBounds();
	sf::FloatRect paddleBounds = paddle.getGlobalBounds();
	return ballBounds.intersects(paddleBounds);
}


// constructor/destructor
Engine::Engine() {
	this->initVariables();
	this->initWindow();

}
Engine::~Engine() {
	delete this->window;
}


// accessors
const bool Engine::isRunning() const {
	return this->window->isOpen();
}


// functions

void Engine::pollEvents() {
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;

		}
	}
}


void Engine::update() {

	dt = dtClock.restart().asSeconds();

	this->pollEvents();

	this->playerPaddle_1.update(this->window);
	this->playerPaddle_2.update(this->window);
	//this->paddleAI.update(this->window, this->ball.shape, dt);
	this->ball.update(this->window);
	if (this->paddleBallCollision(this->ball.shape, this->playerPaddle_1.shape) || this->paddleBallCollision(this->ball.shape, this->paddleAI.shape) || this->paddleBallCollision(this->ball.shape, this->playerPaddle_2.shape))
	{
		this->ball.direction.x = -this->ball.direction.x;
		this->ball.movementSpeed += 0.25f;
	}



}



void Engine::render() {
	// render
	this->window->clear();
	this->playerPaddle_1.render(this->window);
	this->playerPaddle_2.render(this->window);
	//this->paddleAI.render(this->window);
	this->ball.render(this->window);
	this->window->display();


}
