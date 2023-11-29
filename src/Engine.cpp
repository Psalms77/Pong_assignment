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


}



void Engine::render() {
	// render
	this->window->clear();
	this->playerPaddle_1.render(this->window);

	this->window->display();


}
