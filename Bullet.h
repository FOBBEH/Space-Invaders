#ifndef BULLET_H
#define BULLET_H

#include <vector>

#include "SpriteManager.h"
#include "Object.h"

struct Bullet : public Object
{
	// :D:D:D:D:D:D:D:D:D:D
};

// NEW VECTOR DEFINITION:
typedef std::vector<Bullet> BulletList;

extern BulletList PlayerBullets;
extern BulletList EnemyBullets;

// FUNCTIONS:
extern bool bulletCanBeFired;

void UpdateBullets(RenderWindow &window, float deltaT);
void RenderBullets(RenderWindow &window);

bool PlayerBulletOffScreen(Bullet &bullet);
bool EnemyBulletOffScreen(Bullet &bullet);
bool BulletIsDead(Bullet &bullet);

#endif // BULLET_H