#include "game_state.h"

game_state* state;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Santa's Sleigh Ride");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}
