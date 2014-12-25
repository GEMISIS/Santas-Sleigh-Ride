#include <stdio.h>
#include "main_menu.h"
#include "main_game.h"

void main_menu::Initialize(sf::RenderWindow* window)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("SnowForSanta.ttf");

	this->titleTop = new sf::Text("Santa's Sleigh", *font, 100U);
	this->titleBottom = new sf::Text("Ride", *font, 100U);

	this->titleBottom->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 2, this->titleBottom->getCharacterSize() / 2));
	this->titleBottom->setPosition(sf::Vector2f(window->getSize().y / 2, this->titleTop->getCharacterSize() * 1.5f));

	this->play = new sf::Text("Play", *font, 64U);
	this->quit = new sf::Text("Quit", *font, 64U);

	this->play->setPosition(sf::Vector2f(window->getSize().y / 2 + this->play->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 3.5f));
	this->quit->setPosition(sf::Vector2f(window->getSize().y / 2 + this->quit->getGlobalBounds().width / 2, this->titleTop->getCharacterSize() * 3.5f + this->play->getCharacterSize() * 1.0f));

	this->play->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 2, this->titleBottom->getCharacterSize() / 2));
	this->quit->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 2, this->titleBottom->getCharacterSize() / 2));

	this->grow = 0.0025f;
	this->scaleSize = 1.0f;

	this->selected = 0;
}
void main_menu::Update(sf::RenderWindow* window)
{
	this->scaleSize += this->grow;
	if (this->scaleSize > 1.25f || this->scaleSize < 0.75f)
	{
		this->grow *= -1.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !downKey)
	{
		this->selected += 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !upKey)
	{
		this->selected -= 1;
	}
	
	if (this->selected > 1)
	{
		this->selected = 0;
	}
	if (this->selected < 0)
	{
		this->selected = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->selected)
		{
		case 0:
			coreState->SetState(new main_game());
			break;
		case 1:
			exitGame = true;
			break;
		}
	}
	
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}
void main_menu::Render(sf::RenderWindow* window)
{
	this->play->setScale(sf::Vector2f(1, 1));
	this->quit->setScale(sf::Vector2f(1, 1));

	switch (this->selected)
	{
	case 0:
		this->play->setScale(sf::Vector2f(scaleSize, scaleSize));
		break;
	case 1:
		this->quit->setScale(sf::Vector2f(scaleSize, scaleSize));
		break;
	}

	window->draw(*this->titleTop);
	window->draw(*this->titleBottom);

	window->draw(*this->play);
	window->draw(*this->quit);
}
void main_menu::Destroy(sf::RenderWindow* window)
{
}

