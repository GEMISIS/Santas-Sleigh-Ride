#pragma once

#include "Entity.h"

extern int bullets;

class Present : public Entity
{
public:
	Present(float x, float y);
	void Update();
private:
	float direction = 0;
};