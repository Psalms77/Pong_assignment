#include "Engine.h"

//	init
void Engine::initVariables() {

	// init basic
	dt = 0.f;
	this->isSinglePlayer = false;
	this->isMultiPlayer = false;
	this->isStartScene = true;
	this->isPaused = false;
	this->prePauseBallSpeed = 0.f;
	this->window = nullptr;
	this->player1Score = 0;
	this->player2Score = 0;
	this->isResetting = false;
	this->resettingTime = 1.5f;
	this->resettingTimer = 0.f;
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

void Engine::updatewindowboundscollision(const sf::RenderTarget* target, const sf::CircleShape& b)
{	// bouncing off window top and bottom bounds

	sf::FloatRect ballBounds = b.getGlobalBounds();

	if (ballBounds.top <= 0.f || ballBounds.top + ballBounds.height >= target->getSize().y)
	{
		this->ball.direction.y = -this->ball.direction.y;
		//this->direction.y = -this->direction.y;
	}
	if (ballBounds.left <= 0.f)
	{
		this->isResetting = true;
		this->ball.shape.setPosition(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
		this->player2Score += 1;
	}
	if (ballBounds.left + ballBounds.width >= target->getSize().x)
	{
		this->isResetting = true;
		this->ball.shape.setPosition(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
		this->player1Score += 1;
	}
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
		case sf::Event::KeyReleased:
			if (this->ev.key.code == sf::Keyboard::P)
			{
				this->isPaused = !this->isPaused;
				std::cout << "ispaused: ( " << isPaused << ")" << std::endl;
				if (!isStartScene && isPaused)
				{
					//record pre pause info
					this->prePauseBallSpeed = this->ball.movementSpeed;
					this->ball.movementSpeed = 0.f;
				}
				else if (!isPaused) {
					this->ball.movementSpeed = this->prePauseBallSpeed;
				}
			}
			break;

		}
	}
}


void Engine::update() {

	dt = dtClock.restart().asSeconds();

	this->pollEvents();

	// main game logic
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
	else if (isSinglePlayer && !isPaused)
	{
		this->ui.update(this->window, this->player1Score, this->player2Score);
		this->updatewindowboundscollision(this->window, this->ball.shape);
		if (this->isResetting)
		{
			this->resettingTimer += dt;

			if (this->resettingTimer>=1.f)
			{
				this->ball.shape.setPosition(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
			}

			if (this->resettingTimer >= this->resettingTime)
			{
				this->isResetting = false;
				this->resettingTimer = 0.f;
				this->ball.reset();
			}
		}
		else
		{
			
			this->playerPaddle_1.update(this->window);
			this->paddleAI.update(this->window, this->ball.shape, dt);
			this->ball.update(this->window);
			if (this->paddleBallCollision(this->ball.shape, this->playerPaddle_1.shape) || this->paddleBallCollision(this->ball.shape, this->paddleAI.shape))
			{
				this->ball.direction.x = -this->ball.direction.x;
				this->ball.movementSpeed += 0.25f;
			}			
		}


	}
	else if (isMultiPlayer && !isPaused)
	{
		this->ui.update(this->window, this->player1Score, this->player2Score);
		this->updatewindowboundscollision(this->window, this->ball.shape);
		if (this->isResetting)
		{
			this->resettingTimer += dt;

			if (this->resettingTimer >= 1.f)
			{
				this->ball.shape.setPosition(this->window->getSize().x / 2.f, this->window->getSize().y / 2.f);
			}

			if (this->resettingTimer >= this->resettingTime)
			{
				this->isResetting = false;
				this->resettingTimer = 0.f;
				this->ball.reset();
			}
		}
		else
		{
			
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

}



void Engine::render() {
	// render
	this->window->clear();
	

	// main render logic
	if (isStartScene)
	{
		this->ui.render(this->window, 0);
	}
	else if (isSinglePlayer)
	{
		if (this->isResetting && this->resettingTimer < 0.5f)
		{

		}
		else if (this->isResetting && this->resettingTimer > 0.5f && this->resettingTimer > 1.f) {
			this->ui.render(this->window, 1);
		}
		else
		{
			this->ui.render(this->window, 1);
			this->ball.render(this->window);
		}
		this->playerPaddle_1.render(this->window);
		this->paddleAI.render(this->window);

	}
	else if (isMultiPlayer)
	{
		if (this->isResetting && this->resettingTimer < 0.5f)
		{

		}
		else if (this->isResetting && this->resettingTimer > 0.5f && this->resettingTimer > 1.f) {
			this->ui.render(this->window, 1);
		}
		else
		{
			this->ui.render(this->window, 1);
			this->ball.render(this->window);
		}
		this->playerPaddle_1.render(this->window);
		this->playerPaddle_2.render(this->window);
	}
	this->window->display();


}
