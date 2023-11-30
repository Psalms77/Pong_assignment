#include "Engine.h"

//	init
void Engine::initVariables() {

	// init basic
	dt = 0.f;
	this->isSinglePlayer = false;
	this->isMultiPlayer = false;
	this->isStartScene = true;

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
	
	if (isStartScene)
	{
		//this->ui.update(this->window, this->ball.player1Score, this->ball.player2Score);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			isStartScene = false;
			isSinglePlayer = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			isStartScene = false;
			isMultiPlayer = true;
		}
	}
	else if (isSinglePlayer)
	{
		this->ui.update(this->window, this->ball.player1Score, this->ball.player2Score);
		this->playerPaddle_1.update(this->window);
		this->paddleAI.update(this->window, this->ball.shape, dt);
		this->ball.update(this->window);
		if (this->paddleBallCollision(this->ball.shape, this->playerPaddle_1.shape) || this->paddleBallCollision(this->ball.shape, this->paddleAI.shape))
		{
			this->ball.direction.x = -this->ball.direction.x;
			this->ball.movementSpeed += 0.25f;
		}
	}
	else if (isMultiPlayer)
	{
		this->ui.update(this->window, this->ball.player1Score, this->ball.player2Score);
		this->playerPaddle_1.update(this->window);
		this->playerPaddle_2.update(this->window);
		this->ball.update(this->window);
		if (this->paddleBallCollision(this->ball.shape, this->playerPaddle_1.shape) || this->paddleBallCollision(this->ball.shape, this->playerPaddle_2.shape))
		{
			this->ball.direction.x = -this->ball.direction.x;
			this->ball.movementSpeed += 0.25f;
		}
	}
}



void Engine::render() {
	// render
	this->window->clear();
	
	if (isStartScene)
	{
		this->ui.render(this->window, 0);
	}
	else if (isSinglePlayer)
	{
		this->ui.render(this->window, 1);
		this->playerPaddle_1.render(this->window);
		this->paddleAI.render(this->window);
		this->ball.render(this->window);
	}
	else if (isMultiPlayer)
	{
		this->ui.render(this->window, 2);
		this->playerPaddle_1.render(this->window);
		this->playerPaddle_2.render(this->window);
		this->ball.render(this->window);
	}
	this->window->display();


}
