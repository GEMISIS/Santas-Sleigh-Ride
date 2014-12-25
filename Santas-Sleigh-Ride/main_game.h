#include "game_state.h"

#include "EntityManager.h"
#include "Santa.h"

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
	Santa santa;
};

