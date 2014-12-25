#include "game_state.h"
#include "test_state.h"

game_state* coreState;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Santa's Sleigh Ride");

	coreState = new game_state(&window);
	coreState->SetState(new test_state());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		coreState->Update();
	}

	return 0;
}
