#include "House.h"
#include "main_game.h"

House::House()
{
	houseCount += 1;
	this->group_id = 3;
	this->Load("house.png", sf::IntRect());
	this->setPosition(sf::Vector2f(rand() % 400 + 800, rand() % 600));
	this->setColor(sf::Color::Color(rand() % 255, rand() % 255, rand() % 255));
	this->setScale(sf::Vector2f(4, 4));
}

void House::Update()
{
	if (this->active)
	{
		this->move(sf::Vector2f(-0.75f, 0));

		if (this->getGlobalBounds().left + this->getGlobalBounds().width < 0)
		{
			houseCount -= 1;
			this->active = 0;
		}
	}
}