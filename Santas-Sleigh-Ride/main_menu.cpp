#include <stdio.h>
#include "main_menu.h"
#include "test_state2.h"

void main_menu::Initialize(sf::RenderWindow* window)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("SnowForSanta.ttf");

	this->titleTop = new sf::Text("Santa's Sleigh", *font, 100U);
	this->titleBottom = new sf::Text("Ride", *font, 100U);

	this->titleBottom->setOrigin(sf::Vector2f(this->titleBottom->getCharacterSize() / 2, this->titleBottom->getCharacterSize() / 2));
	this->titleBottom->setPosition(sf::Vector2f(window->getSize().y / 2, this->titleTop->getCharacterSize() * 1.5f));
}
void main_menu::Update(sf::RenderWindow* window)
{
}
void main_menu::Render(sf::RenderWindow* window)
{
	window->draw(*this->titleTop);
	window->draw(*this->titleBottom);
}
void main_menu::Destroy(sf::RenderWindow* window)
{
	printf("destroyed!");
}

