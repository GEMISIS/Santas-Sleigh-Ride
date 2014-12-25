#include "Present.h"

Present::Present(float x, float y)
{
	this->Load("presents.png", sf::IntRect());
	this->setPosition(sf::Vector2f(x, y));
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
}

void Present::Update()
{
	if (this->active)
	{
		this->move(sf::Vector2f(1.0f, 0));
		this->rotate(1);

		if (this->getGlobalBounds().left + this->getGlobalBounds().width > 800)
		{
			this->active = 0;
		}
	}
}