#pragma once

#include <SFML/Graphics.hpp>
#include "EntityManager.h"

class tiny_state
{
public:
	EntityManager manager;
	virtual void Initialize(sf::RenderWindow* window)
	{
	}
	virtual void Update(sf::RenderWindow* window)
	{
	}
	virtual void Render(sf::RenderWindow* window)
	{
	}
	virtual void Destroy(sf::RenderWindow* window)
	{
	}
private:
};

class game_state
{
public:
	game_state(sf::RenderWindow* window)
	{
		this->window = window;
	}

	void SetState(tiny_state* nextState)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
		this->state = nextState;
		if (this->state != NULL)
		{
			this->state->Initialize(this->window);
		}
	}

	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update(this->window);
			this->state->Render(this->window);
		}
	}

	~game_state()
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
	}
	tiny_state* state;
private:
	sf::RenderWindow* window;
};

extern game_state* coreState;
extern bool exitGame;