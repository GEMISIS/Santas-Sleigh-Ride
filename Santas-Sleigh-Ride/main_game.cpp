#include <stdio.h>
#include <string>
#include "main_game.h"
#include "main_menu.h"
#include "game_over.h"
#include "House.h"

int houseCount;
int score = 0;
int lives = 3;

void main_game::Initialize(sf::RenderWindow* window)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile("SnowForSanta.ttf");

	this->scoreText = new sf::Text("Score: 0", *font, 32U);

	this->livesText = new sf::Text("Lives: 3", *font, 32U);
	this->livesText->setPosition(sf::Vector2f(800 - this->livesText->getGlobalBounds().width, 0));

	manager.AddEntity("Santa", new Santa());
}
void main_game::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState->SetState(new main_menu());
	}

	if (houseCount < 10)
	{
		this->manager.AddEntity("house", new House());
	}

	if (lives < 1)
	{
		lives = 3;
		score = 0;
		coreState->SetState(new game_over());
	}

	this->scoreText->setString("Score:" + std::to_string(score));
	this->livesText->setString("Lives:" + std::to_string(lives));

	this->manager.Update();
}
void main_game::Render(sf::RenderWindow* window)
{
	this->manager.Render(window);
	window->draw(*this->scoreText);
	window->draw(*this->livesText);
}
void main_game::Destroy(sf::RenderWindow* window)
{
}

