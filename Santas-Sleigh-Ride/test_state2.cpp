#include <stdio.h>
#include "test_state2.h"
#include "main_menu.h"

void test_state2::Initialize(sf::RenderWindow* window)
{
	printf("created2!");
}
void test_state2::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState->SetState(new main_menu());
	}
}
void test_state2::Render(sf::RenderWindow* window)
{
}
void test_state2::Destroy(sf::RenderWindow* window)
{
	printf("destroyed2!");
}

