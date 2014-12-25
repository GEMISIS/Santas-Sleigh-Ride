#include <stdio.h>
#include "test_state.h"
#include "test_state2.h"

void test_state::Initialize(sf::RenderWindow* window)
{
	printf("created!");
}
void test_state::Update(sf::RenderWindow* window)
{
	coreState->SetState(new test_state2());
}
void test_state::Render(sf::RenderWindow* window)
{
}
void test_state::Destroy(sf::RenderWindow* window)
{
	printf("destroyed!");
}

