#include <stdio.h>
#include "main_game.h"
#include "main_menu.h"

void main_game::Initialize(sf::RenderWindow* window)
{
	manager.AddEntity("Santa", new Santa());
}
void main_game::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState->SetState(new main_menu());
	}

	this->manager.Update();
}
void main_game::Render(sf::RenderWindow* window)
{
	this->manager.Render(window);
}
void main_game::Destroy(sf::RenderWindow* window)
{
}

