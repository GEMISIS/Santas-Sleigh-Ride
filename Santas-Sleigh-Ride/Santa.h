#pragma once

#include "Entity.h"

class Santa : public Entity
{
public:
	Santa();
	void Update();
private:
	bool upKey, downKey, leftKey, rightKey, spaceKey;
};
