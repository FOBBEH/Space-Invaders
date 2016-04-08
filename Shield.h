#ifndef SHIELD_H
#define SHIELD_H

#include <vector>

#include "SpriteManager.h"
#include "Object.h"

struct Shield : public Object
{
	int durability;
};

// NEW VECTOR DEFINITION:
typedef std::vector<Shield> ShieldList;

extern ShieldList ShieldListA;
extern ShieldList ShieldListB;
extern ShieldList ShieldListC;
extern ShieldList ShieldListD;

// FUNCTIONS:
void CreateShields();

void UpdateShields(float deltaT);
void RenderShields(RenderWindow &window);

#endif // SHIELD_H