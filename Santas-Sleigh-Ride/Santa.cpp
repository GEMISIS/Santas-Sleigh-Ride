#include "Santa.h"
#include "game_state.h"
#include "Present.h"

Santa::Santa()
{
	this->Load("santa.png", sf::IntRect());
}

void Santa::Update()
{
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
	this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);

	if (this->upKey)
	{
		this->move(sf::Vector2f(0, -1));
	}
	if (this->downKey)
	{
		this->move(sf::Vector2f(0, 1));
	}
	if (this->leftKey)
	{
		this->move(sf::Vector2f(-1, 0));
	}
	if (this->rightKey)
	{
		this->move(sf::Vector2f(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->spaceKey)
	{
		coreState->state->manager.AddEntity("present", new Present(this->getPosition().x, this->getPosition().y));
	}
	this->spaceKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}
