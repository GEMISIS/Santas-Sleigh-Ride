#pragma once

#include "Entity.h"

extern int bullets;

class Santa : public Entity
{
public:
	Santa();
	void Update();
private:
	bool upKey, downKey, leftKey, rightKey, spaceKey;
};
