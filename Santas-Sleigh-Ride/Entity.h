#include <SFML/Graphics.hpp>
#include <string>

class Entity : sf::Sprite
{
public:
	Entity(std::string filename)
	{
		this->texture = new sf::Texture();
		this->Load(filename, sf::IntRect());
	}
	Entity(std::string filename, sf::IntRect size)
	{
		this->texture = new sf::Texture();
		this->Load(filename, size);
	}

	void Load(std::string filename, sf::IntRect size)
	{
		this->texture->loadFromFile(filename, size);
		this->setTexture(*this->texture);
	}
private:
	sf::Texture* texture;
};

