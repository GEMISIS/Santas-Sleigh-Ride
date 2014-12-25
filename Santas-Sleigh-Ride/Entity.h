#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity : public sf::Sprite
{
public:
	Entity()
	{
		this->active = 1;
		this->texture = new sf::Texture();
	}
	Entity(std::string filename)
	{
		this->active = 1;
		this->texture = new sf::Texture();
		this->Load(filename, sf::IntRect());
	}
	Entity(std::string filename, sf::IntRect size)
	{
		this->active = 1;
		this->texture = new sf::Texture();
		this->Load(filename, size);
	}

	void Load(std::string filename, sf::IntRect size)
	{
		this->texture->loadFromFile(filename, size);
		this->setTexture(*this->texture);
	}

	int Active()
	{
		return this->active;
	}

	virtual void Update()
	{
	}

	virtual void Render(sf::RenderWindow* window)
	{
		window->draw(*this);
	}

	~Entity()
	{
	}
protected:
	int active;
private:
	sf::Texture* texture;
};

