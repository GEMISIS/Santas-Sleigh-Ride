#pragma once

#include <unordered_map>
#include <vector>

#include "Entity.h"

class EntityManager
{
public:
	EntityManager()
	{
	}

	void AddEntity(std::string name, Entity* entity)
	{
		std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
		while (found != this->entities.end())
		{
			name += "0";
			found = this->entities.find(name);
		}
		this->entities.insert(std::make_pair(name, entity));
	}

	void Update()
	{
		for (auto& iterator : this->entities)
		{
			if (iterator.second->Active())
			{
				iterator.second->Update();
			}
			else
			{
				toRemove.push_back(iterator.first);
			}
		}

		while (toRemove.size() > 0)
		{
			this->entities.erase(toRemove[0]);
			toRemove.pop_back();
		}
	}

	void Render(sf::RenderWindow* window)
	{
		for (auto& iterator : this->entities)
		{
			if (iterator.second->Active())
			{
				iterator.second->Render(window);
			}
		}
	}

	~EntityManager()
	{
	}
private:
	std::unordered_map<std::string, Entity*> entities;
	std::vector<std::string> toRemove;
};