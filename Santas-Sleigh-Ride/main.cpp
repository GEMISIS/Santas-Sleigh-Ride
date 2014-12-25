#include "game_state.h"
#include "main_menu.h"

game_state* coreState;
bool exitGame = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Santa's Sleigh Ride");

	coreState = new game_state(&window);
	coreState->SetState(new main_menu());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		if (exitGame)
		{
			window.close();
		}

		coreState->Update();

		window.display();
	}

	return 0;
}
