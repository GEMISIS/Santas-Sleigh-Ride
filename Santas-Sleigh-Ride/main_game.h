#pragma once

#include "game_state.h"

#include "EntityManager.h"
#include "Santa.h"

extern int houseCount;

class main_game : public tiny_state
{
public:
	main_game()
	{
	}
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	sf::Text* score;
	sf::Text* lives;
};


